#include <iostream>

using namespace std;

int main()
{
    int num;
    setlocale(LC_ALL, "ru");
    wcout << "Введите четырехзначное число" << endl;
    cin >> num;
    for (int i = 0; i <= 50; i++)
        cout << i << endl;


    cout << "Чётные из ряда:" << endl;
    for (int i = 0; i <= 50;)
    {
        while (i <= 50)
        {
            if (i % 2 == 0)
                cout << i << endl;
            i++;
        }
    }


    cout << "Цикл выполнился" << endl;
    for (int i = 0; i < num; i++)
    {
        if (i % 1000 == 0)
        {
            cout << i;
            cout << " раз" << endl;
        }
    }

    return 0;
}