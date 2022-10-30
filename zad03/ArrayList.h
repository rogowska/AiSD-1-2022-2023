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
            for (auto x : tab)
            {
                &(x + 1) = &x;
            }
            tab[0] = item;
        }
    }; // dodanie na poczatek

    void push_back(const T &item)
    {
        if (full() == true)
        {
            cout << "ArrayList is full, unable to add element to back" << endl;
        }
        else
        {
            tab[last + 1] = item;
        }
    }; // dodanie na koniec

    T &front()
    {
        if (empty() == true)
        {
            cout << "ArrayList is empty" << endl;
            return NULL;
        }
        else
        {
            return &tab[0];
        }
    }; // zwraca poczatek, nie usuwa, error dla pustej listy

    T &back()
    {
        if (empty() == true)
        {
            cout << "ArrayList is empty" << endl;
            return NULL;
        }
        else
        {
            return &tab[last];
        }
    }; // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front()
    {
        if (empty() == true)
        {
            cout << "ArrayList is empty" << endl;
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

    void display()
    {
        cout << endl
             << "[";
        for (int i = 0; i < last + 1; i++)
        {
            cout << this[i] << " ";
        }
        cout << "]" << endl;
    }; // lepiej zdefiniowac operator<<

    void reverse()
    {
        ArrayList<T> reversedArray = new ArrayList(msize);
        while (!empty())
        {
            reversedArray.push_back[*this.front()];
            this.pop_back();
        }
        this = reversedArray;
        delete reversedArray;
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
        int newSize = this.size() + other.size();
        ArrayList<T> mergedArray = new ArrayList(newSize);
        while (!this->empty() && !other.empty())
        {
            if (this->front() < other.front())
            {
                mergedArray.push_front(this->front());
                this->pop_front();
            }
            else
            {
                mergedArray.push_front(other.front());
                other.pop_front();
            }
        }
        if (this->empty())
        {
            while (!other.empty())
            {
                mergedArray.push_front(other.front());
                other.pop_front();
            }
        }
        else
        {
            while (!this->empty())
            {
                mergedArray.push_front(this->front());
                this->pop_front();
            }
        }

    }; //  merges two sorted lists into one
};

#endif

// EOF