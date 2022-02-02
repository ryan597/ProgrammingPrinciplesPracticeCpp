#include <iostream>

class NegativeFactorial
{
public:
    int value;
    NegativeFactorial(int negValue) : value(negValue) {};
};

auto permutation(int a, int b) -> int;
auto combination(int a, int b) -> int;
auto checkNumbers(int a, int b) -> void;


auto main() -> int
try {
    std::cout << "Enter p for permutations or c for combinations followed by two integers a and b (where b <= a)\n";
    char userChoice;
    int a{-1};  // if non integers are entered, a and b will be negative and program exits
    int b{-1};
    int result{};
    std::cin >> userChoice >> a >> b;
    checkNumbers(a, b);

    switch (userChoice)
    {
    case 'p':
        result = permutation(a, b);
        std::cout << "Result of Permutation(";
        break;
    case 'c':
        result = combination(a, b);
        std::cout << "Result of Combination(";
        break;
    default:
        std::cout << "Invalid entry for choice, please enter either 'p' or 'c'\n";
        exit(1);
    }
    std::cout << a << ", " << b << ") = " << result;
}
catch (NegativeFactorial &error) {
    std::cout << "Negative value entered for factorial. Please enter positive values for a and b such that a >= b.\n";
}

auto checkNumbers(int a, int b) -> void
{
    if (a < 0 || b < 0)
    {
        std::cout << "Enter positive integers for a and b.";
        exit(1);
    }
    if (a - b < 0)
    {
        std::cout << "Second integer cannot be larger than the first";
        exit(1);
    }
}

auto factorial(int x) -> int
{
    if (x == 1 || x == 0)
    {
        return 1;
    }
    else if (x < 0)
    {
        throw NegativeFactorial(x);
    }
    else
    {
        return x * factorial(x-1);
    }
}

auto permutation(int a, int b) -> int
{
    return factorial(a) / factorial(a - b);
}

auto combination(int a, int b) -> int
{
    return permutation(a, b) / factorial(b);
}
