#include "point.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <stack>

point o;

//next to top item value in a stack
point next_to_top(std::stack<point> &stack_of_points)
{
    point temp = stack_of_points.top();
    stack_of_points.pop();
    point next_point = stack_of_points.top();
    stack_of_points.push(temp);
    return next_point;
}

//getting distance between two points
double get_distance(point p1, point p2)
{
    double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distance;
}

//getting direction using vector product
double get_direction(point p1, point p2, point p3)
{
    double direction = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return direction;
}

//angle comparement for quicksort
int angle_compare(const void *point1, const void *point2)
{
    point *p1 = (point *)point1;
    point *p2 = (point *)point2;
    double direction = get_direction(o, *p1, *p2);
    if (direction == 0)
    {
        if (get_distance(o, *p1) < get_distance(o, *p2))
            return -1;
        else
            return 1;
    }
    if (direction < 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

std::vector<point> graham(std::vector<point> &points)
{
    int number_of_points = points.size();
    
    std::vector<point> results;
    o = points[0];

    std::stack<point> points_stack;
    int oix = 0;

    // choosing a starting point
    for (int ix = 1; ix < number_of_points; ix++)
    {
        if (points[ix].y < o.y || (points[ix].y == o.y && points[ix].x < o.x))
        {
            o = points[ix];
            oix = ix;
        }
    }

    std::swap(points[0], points[oix]);

    // sorting all points
    qsort(&points[1], number_of_points - 1, sizeof(point), angle_compare);

    // pushing first three points to stack;
    points_stack.push(points[0]);
    points_stack.push(points[1]);
    points_stack.push(points[2]);

    // choosing convex hull points
    for (int i = 3; i < number_of_points; i++)
    {

        while (points_stack.size()>1 and get_direction(next_to_top(points_stack), points_stack.top(), points[i]) <= 0)
        {
            points_stack.pop();
        }
        points_stack.push(points[i]);
    }

    if (points_stack.size() >= 3)
    {
        while(!points_stack.empty()){
            results.push_back(points_stack.top());
            points_stack.pop();
        }
        return results;
    }
    else
    {
        exit(-1);
    }

}
