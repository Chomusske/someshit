// Лабораторная работа 7 задание 2 файл 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include < string.h >
#include <iomanip>
using namespace std;

struct sport {
    char name[20];
    char city[15];
    int lenght;
    int days;
    int members;



};

struct gorod {
    char gorod_name[20];
    int stadion;
    char airport[20]; //yes no
    char vokzal[20]; // yes no



};

struct sport_gorod {
    char sport_name[20];
    char gorod_name1[20];
    int stadion1;
    char sport_airport[20];
    char sport_vokzal[20];
};



int main()
{   
    setlocale(LC_ALL, "rus");
    gorod newgorod;
    sport newsport;
    sport_gorod mix;

    FILE* f_gorod; // переменная для работы с файлом
    f_gorod = fopen("D:\\GOROD.DAT", "ab+");
    FILE* f_sport; // переменная для работы с файлом
    f_sport = fopen("D:\\SPORT.DAT", "ab+");
    vector <gorod> allg;
    vector <sport> alls;
    vector < sport_gorod> mixV;
    while (fread((char*)&newgorod, sizeof(gorod), 1, f_gorod)) {

        allg.push_back(newgorod);
    }

    while (fread((char*)&newsport, sizeof(sport), 1, f_sport)) {
        for (int i = 0; i < allg.size(); i++) {
            if (strstr(newsport.city, allg[i].gorod_name )){
                strcpy(mix.sport_name, newsport.name);
                strcpy(mix.gorod_name1, allg[i].gorod_name);
                strcpy(mix.sport_airport, allg[i].airport);
                strcpy(mix.sport_vokzal, allg[i].vokzal);
                mix.stadion1 = allg[i].stadion;
                
                
                mixV.push_back(mix);

            }
        }
    }

    cout << "Виды спорта в городе проведения которых на стадионе больше 3000 мест, а спортсмены могут прилететь на самолете:" << endl;
    cout << setw(10) << "Вид спорта:" << setw(12) << "Город:" << setw(10) << "  Стадион(вместимость):" << setw(10) << "Аэропорт:"<< setw(10) << "Вокзал:"<< endl;
    for (int i = 0; i < mixV.size(); i++) {
        if ((strstr(mixV[i].sport_airport, "yes")) && (mixV[i].stadion1 > 3000)) {
            cout << setw(12) << mixV[i].sport_name << setw(10) << mixV[i].gorod_name1 << setw(15) << mixV[i].stadion1 << setw(15) << mixV[i].sport_airport << setw(10) << mixV[i].sport_vokzal << endl;

        }
    }
    
   
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
