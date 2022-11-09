#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct DoubleNode
{
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T &item, DoubleNode *nptr = nullptr, DoubleNode *pptr = nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};

template <typename T>
class DoubleList
{
    DoubleNode<T> *head, *tail;

public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList();

    DoubleList(const DoubleList &other);

    DoubleList &operator=(const DoubleList &other);

    bool empty() const { return head == nullptr; }
    int size() const;
    void push_front(const T &item);
    void push_back(const T &item);
    T &front() const { return head->value; }
    T &back() const { return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    void display();
    void display_reversed();
};

template <typename T>
void DoubleList<T>::push_front(const T &item)
{
    if (!empty())
    {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    }
    else
    {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_back(const T &item)
{
    if (!empty())
    {
        tail->next = new DoubleNode<T>(item, nullptr, tail);
        tail = tail->next;
    }
    else
    {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
int DoubleList<T>::size() const
{
    if (empty())
    {
        return 0;
    }
    if (head == tail)
        return 1;

    int counter = 0;
    DoubleNode<T> *iterator = head;
    while (iterator != nullptr)
    {
        iterator = iterator->next;
        counter++;
    }
    return counter;
}

template <typename T>
void DoubleList<T>::display()
{
    DoubleNode<T> *iterator = head;
    while (iterator != nullptr)
    {
        std::cout << iterator->value << " ";
        iterator = iterator->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed()
{
    DoubleNode<T> *iterator = tail;
    while (iterator != nullptr)
    {
        std::cout << iterator->value << " ";
        iterator = iterator->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
void DoubleList<T>::pop_front()
{
    assert(!empty());
    DoubleNode<T> *node = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete node;
}

template <typename T>
void DoubleList<T>::pop_back()
{
    assert(!empty());
    DoubleNode<T> *node = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
DoubleList<T> &DoubleList<T>::operator=(const DoubleList &other)
{
    if (this == &other)
        return *this;

    DoubleList<T> temp(other);
    std::swap(temp.head, head);
    std::swap(temp.tail, tail);

    return *this;
}

template <typename T>
DoubleList<T>::~DoubleList()
{

    for (DoubleNode<T> *node; !empty();)
    {
        node = head->next;
        delete head;
        head = node;
    }
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList &other)
{

    if (other.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new DoubleNode<T>(other.head->value);
        DoubleNode<T> *thisIterator = head;
        DoubleNode<T> *otherIterator = other.head;

        while (otherIterator->next != nullptr)
        {

            thisIterator->next = new DoubleNode<T>(otherIterator->next->value);
            thisIterator = thisIterator->next;
            otherIterator = otherIterator->next;
        }
        tail = otherIterator;
    }
}

#endif
