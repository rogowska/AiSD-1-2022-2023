#include "myprorityqueue.h"

int main()
{
    MyPriorityQueue<int> pq;
    pq.push(1);
    pq.push(11);
    pq.push(3);
    pq.push(4);
    std::cout << "Prority queue: ";
    pq.display();

    MyPriorityQueue<int> pq2(pq);
    std::cout << "Copy constructor test: ";
    pq2.display();

    MyPriorityQueue<int> pq3(std::move(pq));
    std::cout << "Copy constructor test: ";
    pq3.display();
    std::cout << "Queue moved: ";
    pq.display();

    MyPriorityQueue<int> pq4;
    MyPriorityQueue<int> pq5;
    std::cout << "Copy operator test: ";
    pq4 = pq2;
    pq4.display();

    pq5 = std::move(pq4);
    std::cout << "Move operator test: ";
    pq5.display();
    std::cout << "Queue moved: ";
    pq4.display();

    return 0;
}