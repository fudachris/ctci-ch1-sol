#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
    std::cout << "enter string 1 " << std::endl;
    std::string str1 = "";
    getline(std::cin, str1);

    std::cout << "enter string 2 " << std::endl;
    std::string str2 = "";
    getline(std::cin, str2);

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    for (auto it = str1.begin(); it != str1.end(); ++it)
    {
        for (auto ij = str2.begin(); ij != str2.end(); ++ij)
        {
            if (*it == *ij)
            {
                it = str1.erase(it);
                ij = str2.erase(ij);
                it = str1.begin() - 1;
                ij = str2.begin();
                break;
            }
        }
    }

    str1.size() > 1 || str2.size() > 1 ? std::cout << "false" <<std::endl : std::cout << "true" << std::endl;

}
