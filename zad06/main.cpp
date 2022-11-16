#include <iostream>
#include <string>
#include "deque.h"

template <typename T>
void test(MyDeque<T> *array)
{
    std::cout << "Array tested: ";
    array->display();
    MyDeque<T> arrayCopy(*array);
    MyDeque<T> arrayCopy2(10);
    arrayCopy2 = *array;
    std::cout << "Copy constructor test; new array: ";
    arrayCopy.display();
    std::cout << "operator= test: ";
    arrayCopy2.display();
    std::cout << "Array size is: " << array->size() << std::endl;
    if (array->size() >= 2)
    {
        array->pop_back();
        array->pop_front();
        std::cout << "array with first and last element removed: ";
        array->display();
    }
    std::cout << "Array cleared: ";
    array->clear();
    array->display();
}

int main()
{
    MyDeque<int> intArray(11);
    intArray.push_front(6);
    intArray.push_back(0);
    intArray.push_back(4);
    intArray.push_front(1);
    intArray.push_front(2);
    intArray.push_back(8);
    intArray.push_back(3);
    intArray.push_front(5);
    intArray.push_back(0);
    intArray.push_front(4);
    intArray.push_front(9);
    test(&intArray);
    std::cout << std::endl;

    MyDeque<std::string> stringArray(9);
    stringArray.push_front("Anna");
    stringArray.push_back("Wiesiek");
    stringArray.push_back("Dawid");
    stringArray.push_back("Kamil");
    stringArray.push_front("Ewa");
    stringArray.push_back("Julian");
    stringArray.push_back("Krzysiek");
    stringArray.push_front("Ewangelina");
    test(&stringArray);
}