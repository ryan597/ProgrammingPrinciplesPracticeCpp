#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::string b;

    while(std::cin >> a >> b){
        if (a == "|" || b == "|")
            break;
        else
            std::cout << "a: " << a << "\nb: " << b << "\n";
    }
}