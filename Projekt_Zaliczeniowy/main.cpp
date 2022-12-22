#include "point.h"
#include "graham.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

// Dobrze jest mieć możliwość wczytania punktów z pliku tekstowego (x i y w każdym wierszu),
// a na końcu zapis punktów otoczki do pliku wynikowego.
// Można wtedy użyć innych narzędzi (Python+Matplotlib) do narysowania punktów.

int main(int argc, char *argv[])
{
    std::vector<point> points;
    int number_of_points;
    if (argc > 1)

    {
        std::ifstream myfile;
        std::string filename = argv[1];
        point new_point;
        int x;
        int y;
        int count = 0;
        myfile.open(filename);
        if (myfile.is_open())
        {
            while (myfile.good())
            {
                myfile >> x >> y;
                new_point.x = x;
                new_point.y = y;
                points.push_back(new_point);
                count++;
                std::cout<<count<<std::endl;
            }
        }
        myfile.close();
    }
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

    std::stack<point> result = graham(points, number_of_points);

    while (!result.empty())
    {
        std::cout << "(" << result.top().x << "," << result.top().y << ") ";
        result.pop();
    }
}