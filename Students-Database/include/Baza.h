#ifndef BAZA_H
#define BAZA_H
#include <vector>
#include "Student.h"

class Baza
{
    public:
        vector<Student>studenci;
        void dodajStudenta();
        void wyswietlStudentow();
        void usunStudenta();
        void wczytajStudentow();
        void edytujStudenta();
        void odswiezStudentow();
        void sortujStudentow();
        void sortujStudentowWgOceny();
        void sortujStudentowWgRoku();
    protected:

    private:
};

#endif // BAZA_H
