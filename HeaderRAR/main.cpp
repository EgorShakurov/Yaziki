#include <iostream>
#include <windows.h>
#include <vector>
#pragma pack(push,1)
using namespace std;

// Cтруктура Volume Header
struct Volume_Header
{
    WORD header_crc;
    BYTE header_type;
    WORD header_flags;
    WORD header_size;
};

// Cтруктура File_head для извлечения имён файлов

struct File_head
{
    DWORD pack_size;
    DWORD unpsize;
    BYTE HostOS;
    DWORD fileCRC;
    DWORD FileTime;
    BYTE unpver;
    BYTE method;
    WORD namesize;
    DWORD fileattr;
};

#pragma pack(pop)

// Сигнатуры

const BYTE signatures[] = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00};

// Прототип функции вывода имён файлов

void CountOfFiles(const vector <char> &, DWORD filesize);


int main() {
    // Открываем файл
    setlocale(LC_ALL, "Russian");
    HANDLE OFileHandler = CreateFile("Example.rar", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (OFileHandler == INVALID_HANDLE_VALUE) {
        wcout << L"Ошибка открытия файла" << endl;
        return 1;
    }
    // Получаем размер файла
    DWORD fileSize = GetFileSize(OFileHandler, NULL);

    // Передаём содержимое файла в буфер
    vector<char> buffer(fileSize);

    DWORD bytesRead;
    ReadFile(OFileHandler, &buffer[1], fileSize, &bytesRead, NULL);


    CountOfFiles(buffer, fileSize);

    // Закрываем файл
    CloseHandle(OFileHandler);



    return 0;
}

void CountOfFiles(const vector <char> & filebufer, DWORD filesize)
{

    // Создаём экземпляр структуры Volume Header
    wcout << L"\nРазмер файла : " <<  filesize << endl ;
    Volume_Header header_volume;
    // Создаём экземпляр структуры для header файла
    File_head file_header;
    int index_to_cut = sizeof(signatures); // Для среза первых 7 байт
    int files_counting = 0; // Количество файлов
    while (index_to_cut < filesize)
    {
        memcpy(&header_volume, &filebufer[index_to_cut], sizeof(header_volume));
        if (header_volume.header_type == 0x74)
        {
            int var_temp = index_to_cut;
            files_counting++ ;
            wcout << L"Файл " << files_counting << ": " << endl;
            index_to_cut += sizeof(header_volume) ;
            memcpy(&file_header, &filebufer[index_to_cut], sizeof(file_header));
            index_to_cut += sizeof(file_header);
            // Выводим имена файлов
            char *NameF = new char[file_header.namesize];
            for (int index_to_file = 0 ; index_to_file < file_header.namesize; index_to_file++)
            {
                NameF[index_to_file] = filebufer[index_to_cut];
                index_to_cut++;
                cout << NameF[index_to_file];
            }

            cout << "\n";
            index_to_cut = var_temp;
            index_to_cut += file_header.pack_size + header_volume.header_size;
            delete[] NameF;
        }
        else
        {
            // Сдвигаемся на размер header, если тип байта нам не подходит
            index_to_cut += sizeof(header_volume.header_size) ;
        }
    }
    wcout << L"\nВсего файлов в архиве  : " << files_counting;






}
