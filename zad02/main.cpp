#include <cassert>
#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include "sorting.hpp"

using namespace std;

int main(int, char **)
{

    std::array<int, 10> g = {{9, 4, 7, 3, 6, 8, 2, 1, 5, 0}};
    int b[] = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};
    std::vector<string> v;
    v.push_back("abs");
    v.push_back("we");
    v.push_back("hh");
    v.push_back("ff");
    v.push_back("o");
    v.push_back("ee");
    v.push_back("ssd");
    v.push_back("cd");
    v.push_back("co");
    v.push_back("ab");

    sorting::selectionSort(begin(g), end(g));
    sorting::quickSort(v.begin(), v.end());
    sorting::quickSort(begin(b), end(b));

    // Wykorzystanie funkcji z STL.
    assert(std::is_sorted(v.begin(), v.end()));              // vector, array
    assert(std::is_sorted(std::begin(g), std::end(g)));      // zwykła tablica
    assert(std::is_sorted(b, b + (sizeof(b) / sizeof(*b)))); // zwykła tablica
}