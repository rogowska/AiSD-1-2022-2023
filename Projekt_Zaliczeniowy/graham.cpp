#include "point.h"
#include <vector>

//int get_distance(point p1, point p2){}

//int get_direction(point p1, point p2){}

point graham(std::vector<point> &points, int number_of_points){
    point O = points[0];
    point result;
    for(point p : points){
        if (p.y < O.y){
            O = p;
        }
    };
    return result;
}
