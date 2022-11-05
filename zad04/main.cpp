#include <iostream>
#include <string>
#include "singlelist.h"
using namespace std;

template <typename T>
void test(SingleList<T> list)
{
    cout << "List tested: ";
    list.display();
    cout << "List size is: " << list.size() << endl;
    cout << "List reversed: ";
    list.reverse();
    list.display();
    cout << "List cleared: ";
    list.clear();
    list.display();
}

int main()
{
    SingleList<int> intList;
    intList.push_front(6);
    intList.push_back(0);
    intList.push_back(5);
    intList.push_back(9);
    intList.push_front(3);
    test(intList);
    cout<<endl;

    SingleList<string> stringList;
    stringList.push_front("Anna");
    stringList.push_back("Wiesiek");
    stringList.push_back("Dawid");
    stringList.push_back("Kamil");
    stringList.push_front("Ewa");
    stringList.push_back("Julian");
    stringList.push_back("Krzysiek");
    stringList.push_front("Ewangelina");
    test(stringList);
}