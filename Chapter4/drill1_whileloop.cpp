#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
    double temp{};
    double smallest{10000000000};
    double largest{-10000000000};

    bool cond {false};

    std::setprecision(51);
    while(!cond){
        if (std::cin >> temp){
            std::cout << "\nValue entered: " << temp << "\n";
            if (temp > largest){
                largest = temp;
                std::cout << "The largest value so far is: " << largest << "\n";
            }
            else if (temp < smallest){
                smallest = temp;
                std::cout << "The smallest value so far is: " << smallest << "\n";
            }
        }
        else {
            std::cin.clear();    // reset the fail state
            if (std::cin.peek() == '|') {
                std::cout << "Found end of input marker |\n";
                cond = true;
            } else {
                std::cout << "Invalid input!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}