#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert>

using namespace std;

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

    ArrayList(const ArrayList &other)
    {
        last = other.last;
        msize = other.msize;
        tab = new T(msize);

        for (int i = 0; i < msize; i++)
        {
            tab[i] = other.tab[i];
        }
    }; // copy constructor
    // usage:   ArrayList<int> list2(list1);

    ArrayList &operator=(ArrayList &&other)
    {
        delete tab;

        last = other.last;
        msize = other.msize;
        tab = other.tab;

        other.last = 0;
        other.msize = 0;
        other.tab = nullptr;

        return *this;

    }; // move assignment operator, return *this
    // usage:   list2 = std::move(list1);

    bool empty() const { return last == 0; }; // checks if the container has no elements

    bool full() const { return last == msize; }; // checks if the container is full

    int size() const { return last; }; // liczba elementow na liscie

    int max_size() const { return msize; }; // najwieksza mozliwa liczba elementow

    void push_front(const T &item)
    {
        if (full() == true)
        {
            cout << "ArrayList is full, unable to add element to front" << endl;
        }
        else
        {
            for (int i = last; i >= 0; i--)
            {
                tab[i + 1] = tab[i];
            }
            tab[0] = item;
            last++;
        }
    }; // dodanie na poczatek

    void push_back(const T &item)
    {
        if (full())
        {
            cout << "ArrayList is full, unable to add element to back" << endl;
        }
        else
        {
            tab[last] = item;
            last++;
        }
    }; // dodanie na koniec

    T &front()
    {
        if (empty())
        {
            cout << "ArrayList is empty" << endl;
        }
        return tab[0];

    }; // zwraca poczatek, nie usuwa, error dla pustej listy

    T &back()
    {
        if (empty())
        {
            cout << "ArrayList is empty" << endl;
        }
        return tab[last-1];

    }; // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front()
    {
        if (empty() == true)
        {
            cout << "ArrayList is empty" << endl;
        }
        else
        {
            for (int i = 0; i < last; i++)
            {
                tab[i] = tab[i + 1];
            }
            last--;
        }
    }; // usuwa poczatek, error dla pustej listy

    void pop_back()
    {
        if (empty())
        {
            cout << "ArrayList is empty" << endl;
        }
        else
        {

            last--;
        }
    }; // usuwa koniec, error dla pustej listy

    void clear()
    {
        last = 0;

    }; // czyszczenie listy z elementow

    friend ostream &operator<<(ostream &os, const ArrayList &list)
    {
        os << "[ ";
        for (int i = 0; i < list.size(); i++)
        {
            os << list.tab[i] << " ";
        }
        os << "]" << endl;
        return os;
    };

    void reverse()
    {
        if (empty())
        {
            cout << "ArrayList is empty" << endl;
        }
        else if (size() == 1)
            return;

        else
        {
            T *tempTab = new T[size()];

            for (int i = 0; i < last; i++)
            {
                tempTab[i] = tab[last - 1 - i];
            }
            tab = tempTab;
        }

    }; // odwracanie kolejnosci

    void sort()
    {
        if (empty())
        {
            cout << "Array list is empty!" << endl;
            return;
        }
        else
        {
            int i;
            int min;

            for (i = 0; i < last; i++)
            {
                min = i;

                for (int j = i + 1; j < last; j++)
                    if (tab[min] > tab[j])
                        min = j;
                swap(tab[min], tab[i]);
            }
        }
    }; // sortowanie listy

    void merge(ArrayList &other)
    {
        int newSize = this->size() + other.size();
        T *tempTab = new T[newSize];
        int i = 0;
        while (!this->empty() && !other.empty())
        {
            if (this->front() < other.front())
            {
                tempTab[i] = this->tab[0];
                this->pop_front();
            }
            else
            {
                tempTab[i] = other.tab[0];
                other.pop_front();
            }
            i++;
        }
        if (this->empty())
        {
            while (!other.empty())
            {
                tempTab[i] = other.tab[0];
                other.pop_front();
                i++;
            }
        }
        else
        {
            while (!this->empty())
            {
                tempTab[i] = this->tab[0];
                this->pop_front();
                i++;
            }
        }

        this->msize = newSize;
        this->last = newSize;
        this->tab = tempTab;

    } //  merges two sorted lists into one
};

#endif

// EOF