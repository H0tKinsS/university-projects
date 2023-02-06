#include "Test.h"
#include <fstream>
#include <string>
void Test::zaladujPytania(){
    fstream file;
    file.open("pytania.txt", ios::in);
    if (!file.good()){
        cout << "Wystapil problem z plikiem tekstowym!";
        return;
    }
    string linia;
    int pytanie = 0;
    while(!file.eof()){
        Pytanie p;
        getline(file, p.pytanie);
        if (p.pytanie.empty()){
            break;
        }
        getline(file, p.odp_a);
        getline(file, p.odp_b);
        getline(file, p.odp_c);
        getline(file, p.odp_d);
        getline(file, p.praw_odp);
        wszystkie_pytania.push_back(p);
        pytanie++;
    }
    file.close();
    return;
}

void Test::doWynikow(string tekst) {
    fstream file;
    file.open("wyniki.txt", ios::app);
    if (!file.good()){
        cout << "Wystapil problem z plikiem tekstowym!";
        return;
    }
    file << tekst << endl;
    file.close();
}
void Test::edytujPytanie(){
    Pytanie p;
    int nr;
    cout << "Podaj nr pytania do edycji: ";
    cin >> nr;
    nr -=1;
    cin.ignore();
    cout << "Podaj nowa tresc: ";
    getline(cin, wszystkie_pytania.at(nr).pytanie);
    cout << "Podaj nowa odpowiedz a: ";
    getline(cin, wszystkie_pytania.at(nr).odp_a);
    cout << "Podaj nowa odpowiedz b: ";
    getline(cin, wszystkie_pytania.at(nr).odp_b);
    cout << "Podaj nowa odpowiedz c: ";
    getline(cin, wszystkie_pytania.at(nr).odp_c);
    cout << "Podaj nowa odpowiedz d: ";
    getline(cin, wszystkie_pytania.at(nr).odp_d);
    cout << "Podaj nowa prawidlowa odpowiedz: ";
    getline(cin, wszystkie_pytania.at(nr).praw_odp);
    fstream file;
    file.open("pytania.txt", ios::out | ios::trunc);
    for (int i = 0; i < wszystkie_pytania.size(); i++) {
        file << wszystkie_pytania.at(i).pytanie << endl
         << wszystkie_pytania.at(i).odp_a << endl
          << wszystkie_pytania.at(i).odp_b << endl
           << wszystkie_pytania.at(i).odp_c << endl
            << wszystkie_pytania.at(i).odp_d << endl
             << wszystkie_pytania.at(i).praw_odp << endl;
    }
    file.close();
    return;

}
void Test::run(){
    string imie;
    cout << "Podaj swoje imie: ";
    cin >> imie;
    int punkty =0;
    for (Pytanie p : wszystkie_pytania) {
        string odp;
        cout << "Pyt.: " << p.pytanie << endl;
        cout << "Odp. A: " << p.odp_a << endl;
        cout << "Odp. B: " << p.odp_b << endl;
        cout << "Odp. C: " << p.odp_c << endl;
        cout << "Odp. D: " << p.odp_d << endl;
        cout << "Podaj odpowiedz a, b, c lub d: ";
        cin >> odp;
        string pytanie;
        if (odp == p.praw_odp) {
            punkty ++;
            pytanie += p.pytanie+ " +";

        } else {
            pytanie += p.pytanie+" -";
        }
        doWynikow(pytanie);
    }
    string tekst;
    tekst = imie + " Wynik: " + to_string(punkty);
    doWynikow(tekst);
    cout << "Ukonczono test, zdobyte punkty wynosza: " << punkty << endl;
}
