#include <iostream>

// IN A CONVERT.H FILE
class InvalidTemp {};
auto celsius_to_kelvin(const double ctemp) -> double;
auto kelvin_to_celsius(const double ktemp) -> double;
auto fahreneheit_to_celsius(const double ftemp) -> double;
auto celsius_to_fahrenheit(const double ctemp) -> double;
// END OF HEADER FILE

auto main() -> int
try {
    std::cout << "Enter a temperature with unit Celsius (c), Fahrenheit (f) or Kelvin (k)\n";
    double temp {};
    char unit {};
    std::cin >> temp >> unit;
    switch (unit) {
    case 'C':
    case 'c':
        std::cout << "Temperature in Kelvin: " << celsius_to_kelvin(temp) << '\n';
        std::cout << "Temperature in Fahrenheit: " << celsius_to_fahrenheit(temp) << '\n';
        break;
    case 'F':
    case 'f':
    {  // Brackets needed to have ctemp in a different scope to prevent cross initialisation warnings/errors
        auto ctemp = fahreneheit_to_celsius(temp);
        std::cout << "Temperature in Celsius: " << ctemp << '\n';
        std::cout << "Temperature in Kelvin: " << celsius_to_kelvin(ctemp) << '\n';
        break;
    }
    case 'K':
    case 'k':
    {
        auto ctemp = kelvin_to_celsius(temp);
        std::cout << "Temperature in Celsius: " << ctemp << '\n';
        std::cout << "Temperautre in Fahrenheit: " << celsius_to_fahrenheit(ctemp) << '\n';
        break;
    }
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

// IN A  CONVERT.CPP FILE
auto celsius_to_kelvin(const double ctemp) -> double
{
    if (ctemp < -273.15) throw InvalidTemp();
    return ctemp + 273.15;
}

auto kelvin_to_celsius(const double ktemp) -> double
{
    if (ktemp < 0) throw InvalidTemp();
    return ktemp - 273.15;
}

auto fahreneheit_to_celsius(const double ftemp) -> double
{
    const double ctemp = (ftemp - 32) * 5 / 9;
    if (ctemp < -273.15) throw InvalidTemp();
    return ctemp;
}

auto celsius_to_fahrenheit(const double ctemp) -> double
{
    if (ctemp < -273.15) throw InvalidTemp();
    return (ctemp * 9 / 5) + 32;
}
// END OF CONVERT.CPP FILE