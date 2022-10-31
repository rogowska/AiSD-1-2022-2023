#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
    ArrayList<int> lista(10);
    ArrayList<int> lista2(5);
    ArrayList<string> lista3(15);

    lista.push_back(11);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_front(-4);
    lista.push_front(5);
    lista.push_back(6);
    lista.push_back(9);
    lista.push_front(7);
    cout << "Lista numer 1 " << lista;

    lista.reverse();
    cout << "Odwrocona lista nr 1 " << lista;

    lista.sort();
    cout << "Posortowana lista numer 1 " << lista;

    lista2.push_front(75);
    lista2.push_back(71);
    lista2.push_front(17);
    lista2.push_front(4);
    lista2.push_back(22);
    cout << "Lista numer 2 " << lista2;

    lista2.reverse();
    cout << "Odwrocona lista nr 2 " << lista2;

    lista2.sort();
    cout << "Posortowana lista numer 2 " << lista2;

    lista.merge(lista2);
    cout << "Polaczone listy 1 i 2 " << lista;

    lista.pop_back();
    lista.pop_front();
    cout << "Polaczana lista z usunietym pierwszym i ostatnim elementem " << lista;

    lista2.clear();
    cout << "Lista 2 po wyczyszczeniu " << lista2;

    lista3.push_back("ewa");
    lista3.push_front("adam");
    lista3.push_back("jan");
    lista3.push_back("kamil");
    lista3.push_front("julia");
    lista3.push_front("ewangelina");
    cout << "Lista numer 3 " << lista3;
    lista3.reverse();
    cout << "Odwrocona lista numer 3 " << lista3;
    lista3.sort();
    cout << "Posortowana lista numer 3 " << lista3;
    cout << "Pierwszy element listy numer 3 " << lista3.front() << endl;
    cout << "Ostatni element listy numer 3 " << lista3.back() << endl;

    return 0;
}