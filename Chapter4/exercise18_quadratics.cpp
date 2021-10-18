#include <iostream>
#include <cmath>

std::pair<double, double> solve_quadratic(double a, double b, double c)
{
    std::pair<double, double> solution{0, 0};
    // (-b +- sqrt(b^2 -4ac)) / 2a
    double discriminant = pow(b, 2) - (4 * a * c);
    if (discriminant < 0)
        std::cout << "Invalid, negative discriminant\n";

    solution.first = (-b + sqrt(discriminant)) / (2 * a);
    solution.second = (-b - sqrt(discriminant)) / (2 * a);
    return solution;
}

int main()
{
    double a;
    double b;
    double c;
    std::cin >> a >> b >> c;
    std::pair<double, double> solution = solve_quadratic(a, b, c);

    std::cout << "X1 = " << solution.first
        << "\nX2 = " << solution.second << "\n";
    return 0;
}