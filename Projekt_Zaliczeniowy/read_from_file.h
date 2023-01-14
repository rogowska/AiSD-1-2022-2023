#include "point.h"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<point> read_from_file(std:: string filename)
    {
        std::ifstream myfile;
        point new_point;
        int count = 0;
        std::vector<point> points;

        // opening and reading data from file
        myfile.open(filename);
        if (myfile.is_open())
        {

            while (myfile >> new_point.x >> new_point.y)
            {

                points.push_back(new_point);
                count++;
            }
            myfile.close();
            return points;
        }
        else
        {
            exit(-1);
        }
        
}