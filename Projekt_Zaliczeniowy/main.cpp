#include "point.h"
#include "graham.cpp"
#include <iostream>
#include <vector>

int main(){
    std::vector<point> points = {{4, 4}, {3, 2}, {5, 1}, {9, 0}, {0, 3}, {6, 5}, {14, 6}};
    int number_of_points = sizeof(points)/sizeof(point);

    std::cout << number_of_points << std::endl; 

    point result = graham(points, number_of_points);
}