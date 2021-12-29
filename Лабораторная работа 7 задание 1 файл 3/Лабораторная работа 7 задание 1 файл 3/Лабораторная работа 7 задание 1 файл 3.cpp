// Лабораторная работа 7 задание 1 файл 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct sport {
    char name[20];
    char city[15];
    int lenght;
    int days;
    int members;

    void Print() {
        cout << "|_________________________________________________________________________________________|" << endl;

        cout << setw(12) << name << setw(15) << city << setw(15) << lenght << setw(15) << days << setw(15) << members << endl;
    }
    void zadanie(vector <sport> temp) {
        int count = 0;
        int maxnameID;
        int maxlenght = 0;
        if (!temp.size() == 0) {
            cout << "Города, в которых соревнования проводятся не менее 3-х дней с привлечением не менее 300 человек:" << endl;
            cout << "\nНазвание спорта: " << "Город проведения: " << "Длина трассы: " << "Дни соревнования: " << "Число участников: " << endl;
            for (int i = 0; i < temp.size(); i++) {
                if ((temp[i].days >= 3) && (temp[i].members >= 300)) {

                    temp[i].Print();
                    count++;
                }
                if (temp[i].lenght > maxlenght) {
                    maxlenght = temp[i].lenght;
                    maxnameID = i;
                }
            }
            cout << endl << "Название спорта с самой длинной трассой: " << endl;
            temp[maxnameID].Print();
          
        }


    }

};


int main()
{
    setlocale(LC_ALL, "rus");
    FILE* f; // переменная для работы с файлом
    f = fopen("D:\\SPORT.DAT", "ab+");
    sport temp;
    vector <sport> sports;
    while (fread((char*)&temp, sizeof(sport),1,f)) {
        sports.push_back(temp);
    }
    temp.zadanie(sports);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
