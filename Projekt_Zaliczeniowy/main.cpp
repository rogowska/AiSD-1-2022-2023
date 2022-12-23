#include "point.h"
#include "graham.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    std::vector<point> points;
    int number_of_points;

    // checking if program has input file
    if (argc > 1)

    {
        std::ifstream myfile;
        std::string filename = argv[1];
        point new_point;
        int count = 0;

        // opening and reading data from file
        myfile.open(filename);
        if (myfile.is_open())
        {

            while (myfile >> new_point.x >> new_point.y)
            {

                points.push_back(new_point);
                count++;
            }
        }
        else
        {
            std::cout << "Error opening file." << std::endl;
            return -1;
        }
        myfile.close();

        if (count < 3)
        {
            std::cout << "Need more data to run a program." << std::endl;
            return -1;
        }
    }
    // example data points for program without input file
    else
    {
        points = {{2, 5}, {6, 6}, {5, 3}, {4, 2}, {9, 3}, {2, 0}, {-1, 1}, {9, 0}, {6, 1}};
    }

    number_of_points = points.size();

    std::cout << "Data points: ";
    for (point p : points)
    {
        std::cout << "(" << p.x << "," << p.y << ") ";
    }

    std::cout << "number of points: " << number_of_points << std::endl;

    graham(points, number_of_points);

    return 0;
}