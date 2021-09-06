#include <iostream>

int main()
{
    double miles {0};
    double kilometers {0};
    std::cout << "Please enter a number of miles: ";
    std::cin >> miles;
    kilometers = 1.609 * miles;
    std::cout << miles << " miles is " << kilometers << " kilometers\n";
}