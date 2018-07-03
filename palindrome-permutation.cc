#include <iostream>
#include <string.h>
#include <iomanip>
#include <functional>
#include <unordered_set>
#include <algorithm>    
#include <sstream>

int main ()
{
    std::cout << "\n enter string " << std::endl;
    std::string str = "";

    getline (std::cin, str);

    std::stringstream ssStr(str);

    std::string result = "" , tmp = "" ;

    while (getline(ssStr,tmp, ' '))
    {
        result += tmp; 
    }
   
    str = result;

    std::sort (str.begin(), str.end());

    int *array = new int [str.size()]();

    for (auto it = str.begin(); it != str.end(); it++)
    {
        std::string tmp(std::tolower(*it),1);
        std::size_t hash = std::hash<std::string>{}(tmp);
        long index = hash % str.size();

        array[index] += 1;
    }

    int sum = 0;

    for (int i = 0; i < str.size(); i++)
    {
        sum += array[i] % 2;    
    }
    
    if (sum == 1)
    {
        std::cout << "\n palindrome " << std::endl;
        return 0;
    }

    std::cout << "\n not a palindrome " << std::endl;
    return 0;
}
