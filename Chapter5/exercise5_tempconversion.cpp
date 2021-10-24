#include <iostream>

class InvalidTemp {};

auto celsius_to_kelvin(double ctemp) -> double
{
    if (ctemp < -273.15) throw InvalidTemp();
    return ctemp + 273.15;
}

auto kelvin_to_celsius(double ktemp) -> double
{
    if (ktemp < 0) throw InvalidTemp();
    return ktemp - 273.15;
}

auto main() -> int
try {
    std::cout << "Enter a temperature with unit Celsius (c) or Kelvin (k)\n";
    double temp {};
    char unit;
    std::cin >> temp >> unit;
    switch (unit){
        case 'C':
        case 'c':
            std::cout << "Temperature in Kelvin: " << celsius_to_kelvin(temp) << '\n';
            break;
        case 'K':
        case 'k':
            std::cout << "Temperature in Celsius: " << kelvin_to_celsius(temp) << '\n';
            break;
        default:
            std::cout << "Invalid Input\n";
            break;
    }
    return 0;
}
catch (InvalidTemp) {
    std::cout << "error: You have entered a temperature that is below absolute zero (-273.15 Celsius)\n";
    return 1;
}