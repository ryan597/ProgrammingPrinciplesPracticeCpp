#include <iostream>
#include <cmath>

class ComplexNumber {};
auto solve_quadratic(const double a, const double b, const double c) -> std::pair<double, double>;

auto main() -> int
try {
    std::cout << "Enter the values of a, b and c for a quadratic of the form\n"
              << "ax^2 + bx + c = 0\n";
    double a {};
    double b {};
    double c {};
    std::cin >> a >> b >> c;
    auto solution = solve_quadratic(a, b, c);
    std::cout << "X1 = " << solution.first << '\n'
              << "X2 = " << solution.second << '\n';
}
catch (ComplexNumber) {
    std::cout << "error: The values entered give a complex valued solution.\n";
    return 1;
}

auto solve_quadratic(const double a, const double b, const double c) -> std::pair<double, double>
{
    const double determinant = pow(b, 2) - 4 * a * c;
    if (determinant < 0) throw ComplexNumber();
    std::pair<double, double> solution = {(-b + sqrt(determinant))/(2 * a), (-b - sqrt(determinant))/(2 * a)};
    return solution;
}