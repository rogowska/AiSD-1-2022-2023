#include <iostream>
#include "ArrayList.h"
using namespace std;

int main(){
    ArrayList<int> lista(4);
    cout<<lista.empty()<<endl;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    cout<<lista.size()<<endl;
    cout<<lista.max_size()<<endl;
    cout<<lista.empty()<<endl;
    cout<<lista.full()<<endl;
    lista.push_back(9);
    cout<<lista.full()<<endl;
    cout << lista;
    return 0;
}