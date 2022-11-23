#include <vector>
#include <string>
#include <iostream>
#include "onp.h"

int main(){

std::vector<std::string> input { "-6", "2", "/" };
int result = onp(input); 
std::cout << "Result for -6, 2, /:   " << result << std::endl;

std::vector<std::string> input2 { "7", "3", "*" };
result = onp(input2); 
std::cout << "Result for 7 3 *:   " << result << std::endl;

std::vector<std::string> input3 { "1", "4", "-", "5", "*" };
result = onp(input3); 
std::cout << "Result for 1 4 - 5 *:   " << result << std::endl;

std::vector<std::string> input4 { "-6", "2", "+", "6", "+", "2", "*" };
result = onp(input4); 
std::cout << "Result for -6 2 + 6 + 2 *:   " << result << std::endl;
}

