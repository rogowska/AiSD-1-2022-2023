#include "point.h"
#include <iostream>
#include <vector>
#include <fstream>

void write_to_file(std::vector<point> results, std::string filename){
    std::ofstream out_file;
    out_file.open(filename);
        if (out_file.is_open())
        {
        for( point p: results){
        out_file << p.x << " " << p.y << std::endl;
        }
            
        out_file.close();
        }
        else{
            exit(-1);
        }
}