#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    // Одномерные массивы

    // задание 1
    int massiv[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Массив: [";
    for(int a = 0; a < 10; a++)
    {

     
    
        cout << massiv[a] << " ";
    }

    cout << "]";
    


    // задание 2
    int massiv[10];

    srand(time(0));
    for (int a = 0; a < 10; a++) {
       
        massiv[i] = rand() % 21 - 10;
    }


    cout << "Элементы массива: ";
   
    for (int a = 0; a < 10; a++) {
        cout << massiv[a] << " ";
    }
    


  // задание 3
    int massiv[5];

    for (int a = 0; a < 5; a++)
    {
        cout << "Введите элемент массива " << a+1 << ": ";
        cin >> massiv[a];
    }

    cout << "Массив: [ ";
    for (int a = 0; a < 5; i++)
        cout << massiv[a] << " ";
    cout << "]" << endl;
    


   // задание 4
    int massiv[10];

   srand(time(0));
    for (int a = 0; a < 10; a++) {
        massiv[a] = rand() % 21 - 10;
    }


    cout << "Исходный массив: [";
    for (int a = 0; a < 10; a++) {
        cout << massiv[a] << " ";
    }

    cout << "]" << endl;


    for (int a = 0; a < 10; a++)
    {
        if (massiv[a]%2 == 0)
            
            massiv[a] *= 3;
        else

            massiv[a] *= 5;
    }


    cout << "Преобразованный массив: [";
    for (int i = 0; i < 10; i++)
        cout << massiv[i] << " ";
    cout << "]" << endl;
    */


    // двумерный массив

    // задание 1
    int massiv[5][5];

    srand(time(0));

    for (int b = 0; b < 5; b++)
    {
        for (int a = 0; a < 5; a++)
        {
            massiv[b][a] = rand()%21 - 10;
        }
    }

     for (int b = 0; b < 5; b++)
    {
        for (int a = 0; a < 5; a++)
        {
            cout << massiv[a][a] << "\t";
        }
        cout << endl;
    }
    


    // задание 2
    int massiv[5][5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            massiv[i][j] = rand()%21 - 10;
        }
    }

     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massiv[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Сумма элементов в каждой строке:" << endl;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += massiv[i][j];
        }
        cout << "Строка " << i + 1 << ": " << sum << endl;
    }
    


    // задание 3
    int massiv[5][5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            massiv[i][j] = rand()%21 - 10;
        }
    }

    cout << "Исхоный массив:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massiv[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(massiv[i][j] < 0)
                massiv[i][j] = 0;
        }
    }

    cout << endl;

    cout << "Преобразованный массив:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massiv[i][j] << "\t";
        }
        cout << endl;
    }
    */

    return 0;
}
