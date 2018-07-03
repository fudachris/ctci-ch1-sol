#include <iostream>
#include <string.h>
#include <sstream>

int main ()
{
    std::string str = "";

    std::cout << "\n enter string " << std::endl;
    getline (std::cin, str);

    std::cout << "\n str=" << str << std::endl;

    std::stringstream ssStr (str);

    std::string tmp = "";
    std::string result = "";

    while (getline(ssStr,tmp,' '))
    {
        result += tmp;
        result += "%20";
    }

    result = result.substr(0,result.size()-3);

    std::cout << "\n result="<<result<< std::endl;



}
