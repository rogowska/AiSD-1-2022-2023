#include "point.h"
#include "graham.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<point> points = {{4, 4}, {3, 2}, {5, 1}, {9, 0}, {0, 3}, {6, 5}, {14, 6}};
    int number_of_points = points.size();

    std::cout<< "Data points: ";
        for (point p : points)
    {
        std::cout << "(" << p.x << "," << p.y << ") ";
    }

    std::cout << "number of points: " << number_of_points << std::endl; 

    std::stack<point> result = graham(points, number_of_points);
    
}