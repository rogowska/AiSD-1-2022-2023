#include "myqueue.h"
#include <iostream>

int main()
{
    MyQueue<int> queueint;
    queueint.push(13);
    queueint.push(16);
    queueint.push(11);
    queueint.push(15);
    queueint.push(5);
    std::cout << "Int queue: ";
    queueint.display();

    MyQueue<int> queueint2(queueint);
    std::cout << "Copy constructor - Int queue copy test: ";
    queueint2.display();

    MyQueue<int> queueint3;
    queueint3 = queueint;
    std::cout << "Copy operator - Int queue copy test: ";
    queueint3.display();

    queueint.pop();
    std::cout << "Int queue pop test: ";
    queueint.display();

    MyQueue<int> queueintMove(std::move(queueint));
    std::cout << "Move constructor - Int queue move test: ";
    queueintMove.display();
    std::cout << "Moved int queue: ";
    queueint.display();

    MyQueue<int> queueintMove2;
    queueintMove2 = std::move(queueint3);
    std::cout << "Move operator - Int queue test: ";
    queueintMove2.display();
    std::cout << "Moved int queue: ";
    queueint3.display();

    queueint2.clear();
    std::cout << "Int queue clear test: ";
    queueint.display();
}