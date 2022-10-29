#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert> 

template <typename T>
class ArrayList {
    T* tab;
    int msize;
    int last;
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; }
    ArrayList(const ArrayList& other); // copy constructor
    // usage:   ArrayList<int> list2(list1);
    ArrayList& operator=(ArrayList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1);
    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow
    void push_front(const T& item); // dodanie na poczatek
    void push_back(const T& item); // dodanie na koniec
    T& front(); // zwraca poczatek, nie usuwa, error dla pustej listy
    T& back(); // zwraca koniec, nie usuwa, error dla pustej listy
    void pop_front(); // usuwa poczatek, error dla pustej listy
    void pop_back(); // usuwa koniec, error dla pustej listy
    void clear(); // czyszczenie listy z elementow
    void display(); // lepiej zdefiniowac operator<<
    void reverse(); // odwracanie kolejnosci
    void sort(); // sortowanie listy
    void merge(ArrayList& other); //  merges two sorted lists into one
};

#endif

// EOF