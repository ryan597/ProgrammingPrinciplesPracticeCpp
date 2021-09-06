#include <iostream>
#include <string>

int main()
{
    int number_of_words = 0;
    std::string previous = " ";
    std::string current;
    while (std::cin >> current){
        // terminate the program with Ctrl+D (Linux) or Ctrl+Z then Enter (Windows)
        ++number_of_words;
        if (previous == current)
        {
            std::cout << "word number " << number_of_words
                      << " repreated: " << current << '\n';
        }
        previous = current;
    }
}
