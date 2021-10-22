#include <iostream>
#include <string>

auto ask_user(std::string question) -> char
{
    std::cout << question << "? (yes or no)\n";
    std::string answer = " ";
    std::cin >> answer;
    if (answer == "y" || answer == "yes") return 'y';
    if (answer == "n" || answer == "no") return 'n';
    return 'b';  // indicate a bad answer
}

auto area(int length, int width) -> int
{
    if (length <= 0 || width <= 0) return 0;
    return length * width;
}

auto main() -> int
{
    return 0;
}
