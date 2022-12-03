#include <cassert>
#include <iostream>

template <typename T>
class MyQueue
{
    T *tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head;  // pierwszy do pobrania
    int tail;  // pierwsza wolna pozycja
public:
    MyQueue(int s = 10) : msize(s + 1), head(0), tail(0)
    {
        tab = new T[s + 1];
        assert(tab != nullptr);
    } // default constructor
    ~MyQueue() { delete[] tab; }
    MyQueue(const MyQueue &other);            // copy constructor
    MyQueue(MyQueue &&other);                 // move constructor
    MyQueue &operator=(const MyQueue &other); // copy assignment operator, return *this
    MyQueue &operator=(MyQueue &&other);      // move assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (head + msize - 1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize - 1; }
    void push(const T &item);
    void push(T &&item);
    T &front() { return tab[head]; }
    T &back() { return tab[(tail + msize - 1) % msize]; }
    void pop();
    void clear();
    void display();
};

template <typename T>
void MyQueue<T>::push(const T &item)
{
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::push(T &&item)
{
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::display()
{
    for (int i = head; i != tail; i = (i + 1) % msize)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyQueue<T>::clear()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
void MyQueue<T>::pop()
{
    if (!empty())
    {
        tab[head] = T();
        head = (head + msize + 1) % msize;
    }
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue &other)
{
    head = other.head;
    tail = other.tail;
    msize = other.msize;

    tab = new T[msize];

    for (int i = 0; i < msize; i++)
    {
        tab[i] = other.tab[i];
    }
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue &&other)
{

    head = other.head;
    tail = other.tail;
    msize = other.msize;

    tab = new T[msize];

    for (int i = 0; i < msize; i++)
    {
        tab[i] = other.tab[i];
    }

    other.head = 0;
    other.tail = 0;
    other.msize = 0;
    other.tab = nullptr;
}

template <typename T>
MyQueue<T> &MyQueue<T>::operator=(const MyQueue &other)
{

    delete[] tab;

    head = other.head;
    tail = other.tail;
    msize = other.msize;

    tab = new T[msize];

    for (int i = head; i != tail; i = (i + 1) % msize)
        tab[i] = other.tab[i];

    return *this;
}

template <typename T>
MyQueue<T> &MyQueue<T>::operator=(MyQueue &&other)
{
    delete[] tab;

    head = other.head;
    tail = other.tail;
    msize = other.msize;

    tab = new T[msize];

    for (int i = head; i != tail; i = (i + 1) % msize)
        tab[i] = other.tab[i];

    other.head = 0;
    other.tail = 0;
    other.msize = 0;
    other.tab = nullptr;

    return *this;
}