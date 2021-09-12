#include <iostream>

int main()
{
    constexpr double cm_per_inch = 2.54;
    double length = 1;
    char unit = 'a';

    std::cout << "Please enter a length followed by a unit (c or i):\n";
    std::cin >> length >> unit;

    switch (unit){
        case 'i':
            std::cout << length << "in == " << cm_per_inch*length << "cm\n";
            break;
        case 'c':
            std::cout << length << "cm == " << length/cm_per_inch << "in\n";
            break;
        default:
            std::cout << "Sorry, I don't know a unit called " << unit << "\n";
            break;
    }
}