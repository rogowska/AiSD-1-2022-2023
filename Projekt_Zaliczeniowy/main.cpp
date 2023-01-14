#include "point.h"
#include "graham.h"
#include "read_from_file.h"
#include "write_to_file.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>


int main(int argc, char *argv[])
{
    std::vector<point> points;
    std::vector<point> result_points;
    int number_of_points;
    std::string output_filename;

    // checking if program has input and output file names
    if (argc == 3)
    {
        output_filename = argv[2];
        points = read_from_file(argv[1]);
    }
    // example data points for program without input file name
    else if (argc == 1)
    {
        output_filename = "sample_output";
        points = {{2, 5}, {6, 6}, {5, 3}, {4, 2}, {9, 3}, {2, 0}, {-1, 1}, {9, 0}, {6, 1}};
    }
    // help display
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        std::cout << "usage:\n \tprogram_exec_name [input_file] [output_file]\n\n"
                  << std::endl;
        std::cout << "Program implements Graham alghoritm and finds a convex hull of a data points (x, y) provided in file" << std::endl;
        std::cout << "Data points in the input file has to be in format: x y - coordinates of one point for each line in a file." << std::endl;
        std::cout << "When run without parameters it finds convex hull for a hardcoded data points and saves them to sample output file.\n"
                  << std::endl;

        return -1;
    }
    else
    {
        std::cout << "Wrong number of arguments; expected: input file name and output file name." << std::endl;
        std::cout << "Run program with --help or -h parameter for help." << std::endl;
        return -1;
    }

    number_of_points = points.size();

    std::cout << "Data points: " << std::endl;
    for (point p : points)
    {
        std::cout << "(" << p.x << "," << p.y << ") " << std::endl;
    }

    std::cout << "number of points: " << number_of_points << std::endl;

    result_points = graham(points, number_of_points);

    std::cout << "Points found:" << std::endl;

    for(point p: result_points){
        std::cout << "(" << p.x << "," << p.y << ") " << std::endl;
    }
    
    std::cout << "points_stack (convex hull points) size : " << result_points.size() << std::endl;

    write_to_file(result_points, output_filename);

    return 0;
}