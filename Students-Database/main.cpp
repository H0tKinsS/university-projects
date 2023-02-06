#include <iostream>
#include "Student.h"
#include "Baza.h"
using namespace std;

int main()
{
    Baza b;
    while (true){
        int wybor;
        cout << "Wybierz co chcesz zrobic: \n1 - Dodaj studenta\n2 - Edytuj studenta\n3 - Usun studenta\n4 - Sortuj studentow\n5 - Wyswietl studentow\n6 - Wyjscie z programu";
        cin >> wybor;
        switch(wybor){
            case 1:
                system("cls");
               b.dodajStudenta();
               break;
            case 2:
                system("cls");
                b.wczytajStudentow();
                cout << "Liczba studentow: " << b.studenci.size() << endl;
                b.edytujStudenta();
                break;
            case 3:
                system("cls");
                b.wczytajStudentow();
                b.usunStudenta();
                break;
            case 4:
                system("cls");
                b.wczytajStudentow();
                b.sortujStudentow();
                break;
            case 5:
                system("cls");
                b.wczytajStudentow();
                cout << "Liczba studentow: " << b.studenci.size() << endl;
                b.wyswietlStudentow();
                break;
            case 6:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
