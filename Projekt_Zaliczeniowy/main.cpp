#include "point.h"
#include "graham.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

int main(int argc, char *argv[])
{
    std::vector<point> points;
    int number_of_points;

    // checking if program has input and output file names
    if (argc == 3)

    {
        std::ifstream myfile;
        std::string input_filename = argv[1];
        point new_point;
        int count = 0;

        // opening and reading data from file
        myfile.open(input_filename);
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
            std::cout << "Need more data points to run a program." << std::endl;
            return -1;
        }
    }
    // example data points for program without input file name
    else if (argc == 2)
    {
        points = {{2, 5}, {6, 6}, {5, 3}, {4, 2}, {9, 3}, {2, 0}, {-1, 1}, {9, 0}, {6, 1}};
    }
    // help display
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        std::cout << "Program implements Graham alghoritm and finds a convex hull of a data points (x, y)." << std::endl;
        std::cout<< "Program run with parameter [output_file_name.txt] finds convex hull for a hardcoded data points and saves them to output file"<<std::endl;
        std::cout<< "Program run with parameters [output_file_name_.txt] [input_file_name_.txt] uses points from input file and saves results to output file" << std::endl;
        std::cout<< "Data points in the input file has to be in format: x y - coordinates of one point for each line in a file" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Wrong number of arguments; expected: output file name, optionally: input file name." << std::endl;
        std::cout<< "Run program with --help or -h parameter for help"<< std::endl;
        return -1;
    }

    number_of_points = points.size();

    std::cout << "Data points: "<<std::endl;
    for (point p : points)
    {
        std::cout << "(" << p.x << "," << p.y << ") "<<std::endl;
    }

    std::cout << "number of points: " << number_of_points << std::endl;

    graham(points, number_of_points, argv[1]);

    return 0;
}