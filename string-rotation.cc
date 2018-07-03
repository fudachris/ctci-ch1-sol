#include <iostream>
#include <string.h>
#include <algorithm>

std::string
isSubstring (std::string str1, std::string str2)
{
    if (str1.size () == str2.size())
    {
        std::string tmp = str2 + str2;
        if (tmp.find (str1) != std::string::npos)
        {
            return " is a rotation ";
        }
    }

    return " is not a rotation ";
}


int main ()
{
    std::string str1, str2;   
    std::cout << "str1 " << std::endl;
    getline (std::cin, str1);
    
    std::cin.ignore();
    std::cin.clear();

    std::cout << "str2 " << std::endl;
    getline (std::cin, str2);

    std::cout << isSubstring (str1, str2) << std::endl;

    return 0;
}
