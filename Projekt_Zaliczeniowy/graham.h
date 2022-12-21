#include "point.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>

point o;

point next_to_top(std::stack<point> stack_of_points){
    point temp = stack_of_points.top();
    stack_of_points.pop();
    point next_to_top = stack_of_points.top();
    stack_of_points.push(temp);
    return next_to_top;
}

double get_distance(point p1, point p2)
{
    double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distance;
}

double get_direction(point p1, point p2, point p3)
{
    int direction = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return direction;
}

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
        return -1;
    }
    else
    {
        return 1;
    }
}

std::stack<point> graham(std::vector<point> &points, int number_of_points)
{
    o = points[0];
    
    std::stack<point> points_stack;
    int oix;

    // choosing a starting point
    for (int ix = 0; ix < number_of_points; ix ++)
    {
        if (points[ix].y < o.y || (points[ix].y == o.y && points[ix].x < o.x))
        {
            o = points[ix];
            oix = ix;
        }
    }

    std::cout<<"points[0]"<< points[0].x<<" , "<<points[0].y;
    std::cout<<"o"<<o.x<<" , "<<o.y;

    std::swap(points[0], points[oix]);

    // sorting all points
    qsort(&points[1], number_of_points, sizeof(point), angle_compare);
    std::cout << "Points sorted: ";
    for (point p : points)
    {
        std::cout << "(" << p.x << "," << p.y << ") ";
    }

    // pushing first three points to stack;
    points_stack.push(points[0]);
    points_stack.push(points[1]);
    points_stack.push(points[2]);

    for (int i = 3; i < number_of_points; i++)
    {
        do
        {
            points_stack.pop();
        } while (get_direction(next_to_top(points_stack),points_stack.top(),points[i])< 0);
        points_stack.push(points[i]);
    }

    return points_stack;
}
