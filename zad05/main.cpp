#include <iostream>
#include <string>
#include "doublelist.h"

template <typename T>
void test(DoubleList<T> list)
{
    std::cout << "List tested: ";
    list.display();
    DoubleList<T> listcopy(list);
    DoubleList<T> listcopy2;
    listcopy2 = list;
    std::cout << "Copy constructor test; new list: ";
    listcopy.display();
    std::cout << "operator= test: ";
    listcopy2.display() ;
    std::cout << "List size is: " << list.size() << std::endl;
    if (list.size() >= 2)
    {
        list.pop_back();
        list.pop_front();
        std::cout << "List with first and last element removed: ";
    }
    list.display();
    std::cout << "List reversed: ";
    list.display_reversed();
    std::cout << "List cleared: ";
    //list.clear();
    list.display();
}

int main()
{
    DoubleList<int> intList;
    intList.push_front(6);
    intList.push_back(0);
    intList.push_back(5);
    intList.push_back(9);
    intList.push_front(3);
    test(intList);
    std::cout << std::endl;

    DoubleList<std::string> stringList;
    stringList.push_front("Anna");
    stringList.push_back("Wiesiek");
    stringList.push_back("Dawid");
    stringList.push_back("Kamil");
    stringList.push_front("Ewa");
    stringList.push_back("Julian");
    stringList.push_back("Krzysiek");
    stringList.push_front("Ewangelina");
    //test(stringList);
}
