#include "Baza.h"
#include <fstream>
#include <iostream>
using namespace std;
void Baza::odswiezStudentow() {
    fstream plik;
    plik.open("studenci.bin", ios::binary | ios::app);
    if (!plik) {
        cout << "Wystapil nieoczekiwany blad!\n";
        return;
    }
    for (int i = 0; i < studenci.size(); i++) {
        plik.write(reinterpret_cast<char*>(&studenci.at(i)), sizeof(Student));
    }
    plik.close();
}
void Baza::dodajStudenta() {
    fstream plik;
    plik.open("studenci.bin", ios::binary | ios::app);
    if (!plik) {
        cout << "Wystapil nieoczekiwany blad!\n";
        return;
    }
    Student st;
    cout << "Podaj imie: ";
    cin >> st.imie;
    cout << "Podaj nazwisko: ";
    cin >> st.nazwisko;
    cout << "Podaj rok studiow: ";
    cin >> st.rok_studiow;
    cout << "Podaj kierunek: ";
    cin >> st.kierunek;
    cout << "Podaj adres: ";
    cin >> st.adres;
    cout << "Podaj srednia ocen: ";
    cin >> st.srednia_ocen;
    plik.write(reinterpret_cast<char*>(&st), sizeof(Student));
    plik.close();
}
void Baza::wyswietlStudentow(){
    for (Student st : studenci) {
        cout << "Imie: " << st.imie << endl;
        cout << "Nazwisko: " <<  st.nazwisko << endl;
        cout << "Adres: " <<  st.adres << endl;
        cout << "Kierunek: " <<  st.kierunek << endl;
        cout << "Rok Studiow: " <<  st.rok_studiow << endl;
        cout << "Srednia Ocen: " <<  st.srednia_ocen << endl << endl;
    }
}
void Baza::usunStudenta(){
    int indeks;
    cout << "Podaj indeks studenta do usuniecia: ";
    cin >> indeks;
    indeks -= 1;
    studenci.erase(studenci.begin()+indeks);
    ofstream plik("studenci.bin", ios::binary | ios::trunc);
    plik.close();
    odswiezStudentow();
    return;
}
void Baza::wczytajStudentow(){
    cout << "Wczytuje..";
    fstream plik;
    studenci.clear();
    plik.open("studenci.bin", ios::binary | ios::in);
    if (!plik.is_open()){
        cout << "Wystapil nieoczekiwany blad!\n";
        return;
    }
    Student st;
    while(plik.read(reinterpret_cast<char*>(&st), sizeof(Student))) {
        if (!plik) break;
        studenci.push_back(st);
    }
    plik.close();
    return;
}
void Baza::edytujStudenta(){
    int indeks;
    cout << "Podaj indeks studenta do edycji: ";
    cin >> indeks;
    indeks -= 1;
    cout << "Podaj nowe imie: ";
    cin >> studenci.at(indeks).imie;
    cout << "Podaj nowe nazwisko: ";
    cin >> studenci.at(indeks).nazwisko;
    cout << "Podaj nowy rok studiow: ";
    cin >> studenci.at(indeks).rok_studiow;
    cout << "Podaj nowy kierunek: ";
    cin >> studenci.at(indeks).kierunek;
    cout << "Podaj nowy adres: ";
    cin >> studenci.at(indeks).adres;
    cout << "Podaj nowa srednia ocen: ";
    cin >> studenci.at(indeks).srednia_ocen;
    ofstream plik("studenci.bin", ios::binary | ios::trunc);
    plik.close();
    odswiezStudentow();
    return;
}
void Baza::sortujStudentowWgOceny(){

}
void Baza::sortujStudentowWgRoku(){

}

void Baza::sortujStudentow(){
    int wybor;
    cout << "Wybierz metode sortowania: \n1 - Rosnaco\n2 - Malejaco\n";
    cin >> wybor;
    int n = studenci.size();
    switch(wybor){
        case 1:
        cout << "Podaj kryteria:\n1 - Wedlug oceny\n2 - Wedlug Roku\n";
        cin >> wybor;
        switch(wybor) {
        case 1:
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++) {
                    if (studenci.at(j).srednia_ocen > studenci.at(j + 1).srednia_ocen){
                        swap(studenci.at(j), studenci.at(j+1));
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++) {
                    if (studenci.at(j).rok_studiow > studenci.at(j + 1).rok_studiow){
                        swap(studenci.at(j), studenci.at(j+1));
                    }
                }
            }
            break;
        }
        break;
        case 2:
                cout << "Podaj kryteria:\n1 - Wedlug oceny\n2 - Wedlug Roku\n";
            cin >> wybor;
            switch(wybor) {
            case 1:
                for (int i = 0; i < n - 1; i++){
                    for (int j = 0; j < n - i - 1; j++) {
                        if (studenci.at(j).srednia_ocen < studenci.at(j + 1).srednia_ocen){
                            swap(studenci.at(j), studenci.at(j+1));
                            }
                        }
                    }
                break;
                case 2:
                    for (int i = 0; i < n - 1; i++){
                        for (int j = 0; j < n - i - 1; j++) {
                            if (studenci.at(j).rok_studiow < studenci.at(j + 1).rok_studiow){
                                swap(studenci.at(j), studenci.at(j+1));
                            }
                        }
                    }
                    break;
                }
                break;
        }
    ofstream plik("studenci.bin", ios::binary | ios::trunc);
    plik.close();
    odswiezStudentow();

}
