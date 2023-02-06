#include <iostream>
#include "Test.h"
using namespace std;

int main()
{
    system("chcp 1250 >> NULL");
    Test t;
    while (true) {
        int wybor;
        cout << "Witaj, co chcesz zrobic?\n1) Rozpocznij test\n2) Edytuj pytanie\n3) Zakoncz dzialanie programu\n";
        cin >> wybor;
        switch (wybor)
        {
        case 1:
            t.zaladujPytania();
            t.run();
            break;
        case 2:
            t.edytujPytanie();
            break;
        case 3:
            cout << "Wylaczam";
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
