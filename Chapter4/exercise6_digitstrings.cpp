#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int value;
    std::string spelling;
    std::cout << "Enter a digit\n";
    std::cin >> value;
    std::cout << digits[value];
    std::cout << "\nSpell out a digit\n";
    std::cin >> spelling;
    auto ittr = find(digits.begin(), digits.end(), spelling);
    if (ittr == digits.end())
        std::cout << "Not a valid spelling\n";
    else{
        auto index = std::distance(digits.begin(), ittr);
        std::cout << index << "\n";
    }
    return 0;
}