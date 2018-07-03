#include <iostream>
#include <algorithm>

int main ()
{

    std::string str1, str2;

    std::cout << "\n enter first string " << std::endl;
    getline (std::cin, str1);

    std::cout << "\n enter second strig " <<std::endl;
    getline (std::cin, str2);

    std::cout << "\n str1 = " << str1 << std::endl;
    std::cout << "\n str2 = " << str2 << std::endl;


    std::sort (str1.begin(), str1.end());
    std::sort (str2.begin(), str2.end());

    for (auto it = str1.begin(); it != str1.end (); ++it)
    {
        for (auto ij = str2.begin(); ij != str2.end(); ++ij)
        {

            if (*it == *ij)
            {
                it = str1.erase(it);
                ij = str2.erase(ij);
                it=str1.begin()-1;
                ij=str2.begin();
                break;
            }
        }
    }

    std::cout << "\n str1 " << str1.size();
    std::cout << "\n str2 " << str2.size();

    str1.size() == 0 && str2.size() == 0 ? 
    std::cout <<" perm found " << std::endl : std::cout << " nothing found " << std::endl;



    return 0;
}
