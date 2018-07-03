//check if string has all unique characters

#include <iostream>
#include <string.h>
#include <iomanip>
#include <functional>
#include <unordered_set>


bool
isUnique (std::string str)
{
    int *array = new int [str.size()]();
    
    for (size_t i = 0; i < str.size(); i++)
    {
        for (size_t j = 0; j < str.size (); j++)
        {
            if (i != j && str[i] == str[j]) 
            {
                std::string tmp(1,str[i]);
                std::size_t hash = std::hash<std::string>{}(tmp);
                long index = hash % str.size();

                array[index] = array[index] + 1;

                if (array[i] > 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}



int main ()
{
    std::string str;

    std::cout << "Enter a string " << std::endl;
    getline(std::cin,str);
   
    !isUnique (str) == 1 ? std::cout << " repeated char found " << std::endl : std::cout << " unique string "<< std::endl;
    
    return 0;
}
