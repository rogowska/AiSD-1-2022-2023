#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include <cassert>  

template <typename T>
struct SingleNode
{
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} 
    SingleNode(const T &item, SingleNode *ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList
{
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList &other);

    SingleList &operator=(const SingleList &other);

    bool empty() const { return head == nullptr; }
    int size() const;                    
    void push_front(const T &item);        
    void push_back(const T &item);     
    T &back() const { return tail->value; }
    void pop_front();                   
    void pop_back();                       
    void clear();                          
    void display();                        
    void reverse();                         
};

template <typename T>
SingleList<T> &SingleList<T>::operator=(const SingleList &other)
{
    head.value = other->head.value;
    tail.value = other->tail.value;
    head.next = other->head.next;
    tail.next = other->tail.next;

    return *this;
}

template <typename T>
SingleList<T>::SingleList(const SingleList &other)
{

    if (other.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new SingleNode<T>(other.head->value);
        SingleNode<T> *thisIterator = head;
        SingleNode<T> *otherIterator = other.head;

        while (otherIterator->next != nullptr)
        {

            thisIterator->next = new SingleNode<T>(otherIterator->next->value);
            thisIterator = thisIterator->next;
            otherIterator = otherIterator->next;
        }
        tail = otherIterator;
    }
}

template <typename T>
int SingleList<T>::size() const
{
    if (empty())
    {
        return 0;
    }
    if (head == tail)
        return 1;

    int counter = 0;
    SingleNode<T> *iterator = head;
    while (iterator != nullptr)
    {
        iterator = iterator->next;
        counter++;
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
void SingleList<T>::reverse()
{
    if (empty() || head == tail)
    {
        return;
    }

    tail = head;
    SingleNode<T> *nextNode = NULL;
    SingleNode<T> *previous = NULL;

    while (head != nullptr)
    {
        nextNode = head->next;
        head->next = previous;
        previous = head;
        head = nextNode;
    }
    head = previous;
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