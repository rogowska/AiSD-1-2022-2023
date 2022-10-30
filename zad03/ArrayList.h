#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert>

template <typename T>
class ArrayList
{
    T *tab;
    int msize;
    int last;

public:
    ArrayList(int s = 10) : msize(s), last(0)
    {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);
    } // default constructor
    ~ArrayList() { delete[] tab; }

    ArrayList(const ArrayList &other); // copy constructor
    // usage:   ArrayList<int> list2(list1);

    ArrayList &operator=(ArrayList &&other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1);

    bool empty() const { return last == 0; }; // checks if the container has no elements

    bool full() const { return last == msize; }; // checks if the container is full

    int size() const { return last; }; // liczba elementow na liscie

    int max_size() const { return msize; }; // najwieksza mozliwa liczba elementow

    void push_front(const T &item)
    {
        if (full() == true)
        {
            stdout("ArrayList is full, unable to add element to front");
            return NULL;
        }
        for (auto x : tab)
        {
            &(x + 1) = &x;
        }
        tab[0] = item;
    }; // dodanie na poczatek

    void push_back(const T &item)
    {
        if (full() == true)
        {
            stdout("ArrayList is full, unable to add element to back");
            return NULL;
        }
        tab[last + 1] = item;
    }; // dodanie na koniec

    T &front()
    {
        if (empty() == true)
        {
            stdout("ArrayList is empty");
            return NULL;
        }
        else
        {
            return tab[0];
        }
    }; // zwraca poczatek, nie usuwa, error dla pustej listy

    T &back()
    {
        if (empty() == true)
        {
            stdout("ArrayList is empty");
            return NULL;
        }
        else
        {
            return tab[last];
        }
    }; // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front()
    {
        if (empty() == true)
        {
            stdout("ArrayList is empty");
            return NULL;
        }
        else
        {
            for (auto x : tab)
            {
                &x = &(x + 1);
            }
            last--;
        }
    }; // usuwa poczatek, error dla pustej listy

    void pop_back()
    {
        if (empty() == true)
        {
            stdout("ArrayList is empty");
            return NULL;
        }
        else
        {

            last--;
        }
    }; // usuwa koniec, error dla pustej listy

    void clear()
    {
        last = 0;
        // albo
        for (auto x : tab)
        {
            x = NULL;
        }

    }; // czyszczenie listy z elementow

    void display(){}; // lepiej zdefiniowac operator<<

    void reverse(){}; // odwracanie kolejnosci

    void sort(){}; // sortowanie listy

    void merge(ArrayList &other){}; //  merges two sorted lists into one
};

#endif

// EOF