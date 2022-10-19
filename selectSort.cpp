#include <iostream>
#include <vector>
#include <algorithm>

#include <iterator>
#include <vector>
using namespace std;

// Insert sort O(n^2) time O(1) space
template <typename Iterator>
void ins_sort(Iterator first, Iterator end)
{
    for (Iterator cur = first; cur < end; ++cur)
    {
        auto key = *cur;
        Iterator ins = cur - 1;
        for (; first <= ins && key < *ins; --ins)
            *(ins + 1) = *ins; // move 1 to right until correct position's found
        *(ins + 1) = key;
    }
}

template <typename Iterator>
/*void swap(Iterator a, Iterator b)
{
   /auto temp = *a;
    *a = *b;
    *b = temp;
}*/

constexpr void iter_swap(Iterator a, Iterator b)
{
    using std::swap;
    swap(*a, *b);
}

template <typename Iterator>
void selectionSort(Iterator begin, Iterator end)
{
    for (Iterator current = begin; current < end; ++current)
    {
        Iterator min_idx = current;
        for (Iterator search = current + 1; search < end; ++search)
        {
            if (*search < *min_idx)
                min_idx = search;
        }
        iter_swap(min_idx, current);
    }
}

/*void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}*/

template <typename Iterator>
void display(Iterator it, Iterator end)
{
    for (; it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main(int, char **)
{
    std::vector<string> v;
    v.push_back("z");
    v.push_back("x");
    v.push_back("d");
    v.push_back("s");
    v.push_back("w");
    v.push_back("r");
    v.push_back("o");
    v.push_back("g");

    display(v.begin(), v.end());

    selectionSort(v.begin(), v.end());
    display(v.begin(), v.end());
}