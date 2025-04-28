#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251); // Кодировка ввода Windows-1251
    SetConsoleOutputCP(1251); // Кодировка вывода Windows-1251
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество строк в массиве:" << endl;
    cin >> n;

    string* array = new string[n]; // Выделяем память для массива строк

    // Ввод строк
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Удаление дубликатов
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;) // j++ только если НЕ удаляем элемент
        {
            if (array[i] == array[j])
            {
                // Создаем новый массив на 1 элемент меньше
                string* temp = new string[n - 1];

                // Копируем элементы, исключая дубликат
                for (int k = 0, m = 0; k < n; k++)
                {
                    if (k != j) // Пропускаем дубликат
                    {
                        temp[m] = array[k];
                        m++;
                    }
                }

                delete[] array; // Освобождаем старую память
                array = temp; // Указываем на новый массив
                n--; // Уменьшаем размер массива

                // Не увеличиваем j, так как удалённый элемент сместил последующие влево
            }
            else
            {
                j++; // Увеличиваем только если элемент не удалён
            }
        }
    }

    // Вывод массива без дубликатов
    cout << "Массив без дубликатов:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }

    delete[] array; // Освобождаем память перед выходом

    cout << endl << "Введите количество строк в массиве:" << endl;
    cin >> n;

    array = new string[n]; // Выделяем память для массива строк

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Введите значение k:" << endl;
    int k;
    cin >> k;
    if (k > n)
    {
        cout << "Слишком большое значение";
        return 0;
    }
    n = n-k;
    string* temp = new string[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    cout << "Массив без k последних строк:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }

    delete[] array;

    return 0;
}