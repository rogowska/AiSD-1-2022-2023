#include <cassert>

template <typename T>
class MyDeque
{
    T *tab;
    int msize;
    int head;
    int tail;

public:
    MyDeque(int s = 10) : msize(s + 1), head(0), tail(0)
    {
        tab = new T[s + 1];
        assert(tab != nullptr);
    }
    ~MyDeque() { delete[] tab; }
    MyDeque(const MyDeque &other);
    MyDeque &operator=(const MyDeque &other);
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize - 1; }
    void push_front(const T &item);
    void push_back(const T &item);
    T &front() { return tab[head]; }
    T &back() { return tab[(tail + msize - 1) % msize]; }
    void pop_front();
    void pop_back();
    void clear();
    void display();
};

template <typename T>
void MyDeque<T>::push_front(const T &item)
{
    head = (head + msize - 1) % msize;
    tab[head] = item;
}

template <typename T>
void MyDeque<T>::push_back(const T &item)
{
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::display()
{
    for (int i = head; i != tail; i = (i + 1) % msize)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyDeque<T>::clear()
{
    while (!empty())
    {
        pop_back();
    }
}

template <typename T>
void MyDeque<T>::pop_front()
{
    if (!empty())
    {
        tab[head] = T();
        head = (head + msize + 1) % msize;
    }
}

template <typename T>
void MyDeque<T>::pop_back()
{
    if (!empty())
    {
        tab[tail] = T();
        tail = (tail + msize - 1) % msize;
    }
}

template <typename T>
MyDeque<T> &MyDeque<T>::operator=(const MyDeque &other)
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
MyDeque<T>::MyDeque(const MyDeque &other)
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