#include <iostream>

auto celsius_to_kelvin(double ctemp) -> double
{
    return ctemp + 273.15;
}

auto main() -> int
{
    std::cout << "Enter a temperature in Celsius\n";
    double ctemp {};
    std::cin >> ctemp;
    std::cout << "Temperature in Kelvin: " << celsius_to_kelvin(ctemp) << '\n';
    return 0;
}

// Code given for exercise 2 is below. From comparing with above its clear where the errors are,
// and what style changes I think make the code more readable
/*
double ctok(double c)
{
    int k = c + 273.15;
    return int
}

int main()
{
    double c = 0;
    cin >> d;
    double k = ctok("c");
    Cout << j << '/n';
}
*/