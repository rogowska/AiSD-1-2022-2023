#include <iterator>
#include "swap.h"

using namespace std;

template <typename Iterator>
constexpr void iter_swap(Iterator a, Iterator b)
{
    using std::swap;
    swap(*a, *b);
}