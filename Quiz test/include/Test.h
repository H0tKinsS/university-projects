#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <vector>
using namespace std;

struct Pytanie {

    string pytanie;
    string odp_a;
    string odp_b;
    string odp_c;
    string odp_d;
    string praw_odp;

};

class Test
{
    public:
        vector<Pytanie>wszystkie_pytania;
        void zaladujPytania();
        void run();
        void doWynikow(string tekst);
        void edytujPytanie();

    protected:

    private:
};

#endif // TEST_H
