#include <iostream>
#include <string>

int main()
{
    std::string previous = " ";
    std::string current;
    while (std::cin >> current){
        // terminate the program with Ctrl+D (Linux) or Ctrl+Z then Enter (Windows)
        if (previous == current)
        {
            std::cout << "repeated word: " << current << '\n';
        }
        previous = current;
    }
}
