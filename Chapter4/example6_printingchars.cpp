#include <iostream>

int main()
{
    int i = 0;

    while (char('a'+i) != char('z' + 1)){
        std::cout << char('a' + i) << "\t" << int('a' + i) << "\n";
        ++i;
    }

    std::cout << std::endl;

    for (int i=0; char('0' + i) != char('z'+1); i++){
        std::cout << char('0' + i) << "\t" << int('0' + i) << "\n";
    }
}