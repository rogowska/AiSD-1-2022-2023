#include <iterator>
#include "swap.h"
#include "quickSort.h"

using namespace std;

template <typename Iterator>
Iterator partition(Iterator low, Iterator high, Iterator pivot)
{

    Iterator PIndex = low;

    for (Iterator i = low; i < high; i++)
    {

        if (*i <= *pivot)
        {
            iter_swap(PIndex, i);
            PIndex = PIndex + 1;
        }
    }

    PIndex = PIndex - 1;

    return PIndex;
}

template <typename Iterator>
void quickSort(Iterator low, Iterator high)
{

    if (low < high - 1)
    {
        Iterator pivot = high - 1;

        Iterator PIndex = partition(low, high, pivot);

        quickSort(low, PIndex);
        quickSort(PIndex + 1, high);
    }
}