#pragma once
#include <iterator>

namespace sorting
{

    using namespace std;

    //swap function for iterators
    template <typename Iterator>
    constexpr void iter_swap(Iterator a, Iterator b)
    {
        using std::swap;
        swap(*a, *b);
    }

    //partition function for quicksort
    template <typename Iterator>
    Iterator partition(Iterator low, Iterator high, Iterator pivot)
    {

        Iterator find_pivot_position = low;

        for (Iterator i = low; i < high; i++)
        {

            if (*i <= *pivot)
            {
                iter_swap(find_pivot_position, i);
                find_pivot_position = find_pivot_position + 1;
            }
        }

        find_pivot_position = find_pivot_position - 1;

        return find_pivot_position;
    }

    template <typename Iterator>
    void quickSort(Iterator low, Iterator high)
    {

        if (low < high - 1)
        {
            Iterator pivot = high - 1;

            Iterator pivot_position = partition(low, high, pivot);

            quickSort(low, pivot_position);
            quickSort(pivot_position + 1, high);
        }
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

}