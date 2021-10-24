#include <iostream>

class InvalidTemp {};

auto celsius_to_kelvin(double ctemp) -> double
{
    return ctemp + 273.15;
}

auto main() -> int
try {
    std::cout << "Enter a temperature in Celsius\n";
    double ctemp {};
    std::cin >> ctemp;
    if (ctemp < -273.15) throw InvalidTemp();
    std::cout << "Temperature in Kelvin: " << celsius_to_kelvin(ctemp) << '\n';
    return 0;
}
catch (InvalidTemp) {
    std::cout << "error: You have entered a temperature that is below absolute zero (-273.15 Celsius)\n";
    return 1;
}