#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream> // deklaracje strumieni cout, cin, cerr
#include <cassert>  // assert()

template <typename T>
struct SingleNode
{
    // the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T &item, SingleNode *ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() { delete next; } // destruktor DOPISANE
};

template <typename T>
class SingleList
{
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); // tu trzeba wyczyscic wezly

    SingleList(const SingleList &other); // copy constructor
    // usage:   SingleList<int> list2(list1);

    SingleList &operator=(const SingleList &other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    int size() const;                       // O(n) bo trzeba policzyc
    void push_front(const T &item);         // O(1), L.push_front(item)
    void push_back(const T &item);          // O(1), L.push_back(item)
    T &back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front();                       // usuwa poczatek O(1)
    void pop_back();                        // usuwa koniec O(n)
    void clear();                           // czyszczenie listy z elementow O(n)
    void display();                         // O(n)
    void reverse();                         // O(n)
};

template <typename T>
SingleList<T>::SingleList(const SingleList &other)
{
    head = other->head;
    tail = other->tail;
}

template <typename T>
SingleList<T> SingleList<T>::&operator=(const SingleList &other)
{
    head.value = other->head.value;
    tail.value = other->tail.value;
    head.next = other->head.next;
    tail.next = other->tail.next;

    return *this;
}

template <typename T>
int SingleList<T>::size()
{
    int counter = 0;
    SingleNode<T> *iterator = this.head;
    while (iterator != this.tail)
    {
        iterator = iterator->next;
        counter++
    }
    return counter;
}

template <typename T>
void SingleList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
void SingleList<T>::reverse() {

    SingleNode<T> nextNode;
    SingleNode<T> previous;

    while(current != nullptr){
        nextNode = head->next;
        head->next = previous;
        previous = head;
        head = nextNode;
    }
}

template <typename T>
SingleList<T>::~SingleList()
{

    for (SingleNode<T> *node; !empty();)
    {
        node = head->next;
        delete head;
        head = node;
    }
}

template <typename T>
void SingleList<T>::push_front(const T &item)
{
    if (!empty())
    {
        head = new SingleNode<T>(item, head);
    }
    else
    {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T &item)
{
    if (!empty())
    {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    }
    else
    {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display()
{
    SingleNode<T> *node = head;
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front()
{
    assert(!empty());
    SingleNode<T> *node = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back()
{
    assert(!empty());
    SingleNode<T> *node = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        SingleNode<T> *before = head;
        while (before->next != tail)
        {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

#endif