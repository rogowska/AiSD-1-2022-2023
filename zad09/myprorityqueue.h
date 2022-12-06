#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

template <typename T>
class MyPriorityQueue
{
    std::vector<T> lst;

public:
    MyPriorityQueue(int s = 10) { lst.reserve(s); }
    ~MyPriorityQueue() { lst.clear(); }
    MyPriorityQueue(const MyPriorityQueue &other)
    {
        lst = other.lst;
    }
    MyPriorityQueue(MyPriorityQueue &&other)
    {
        lst = other.lst;
        other.lst = nullptr;
    }
    MyPriorityQueue &operator=(const MyPriorityQueue &other)
    {
        lst = other.lst;
        return lst;
    }
    MyPriorityQueue &operator=(MyPriorityQueue &&other)
    {
        lst = other.lst;
        other.lst = nullptr;
        return lst;
    }
    bool empty() const { return lst.empty(); }
    int size() const { return lst.size(); }
    void push(const T &item)
    {
        lst.push_back(item);
        std::push_heap(lst.begin(), lst.end());
    }
    void push(T &&item)
    {
        lst.push_back(std::move(item));
        std::push_heap(lst.begin(), lst.end());
    }
    T &top() { return lst.front(); }
    void pop()
    {
        std::pop_heap(lst.begin(), lst.end());
        lst.pop_back();
    }
    void clear() { lst.clear(); }

    void display()
    {
        std::copy(lst.begin(), lst.end(),
                  std::ostream_iterator<T>(std::cout, " "));
    }
};