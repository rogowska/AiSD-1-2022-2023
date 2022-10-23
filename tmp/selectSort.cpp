#include <iterator>
#include "swap.h"
#include "selectSort.h"

using namespace std;

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