#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>

int main ()
{
    std::cout << "\n enter string " << std::endl;
    std::string str = "";
    getline (std::cin, str);

    size_t count = 1;

    std::string result = "";

    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == *(it+1))
        {
            std::cout << *it << " " << *it << std::endl;
            count += 1;
        }
        else
        {
            std::string tmp (1,*it);
            
            std::cout << "\n tmp " << tmp << std::endl;
            
            result += tmp;

            std::stringstream ssCount;
            ssCount << count;

            result += ssCount.str();

            count = 1;
        }
    }

    std::cout << "\n result = " << result;

}
