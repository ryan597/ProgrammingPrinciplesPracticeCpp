#include <iostream>

class InvalidInput {};
class Overflow
{
public:
    int number;
    Overflow(int b) : number(b) {};
};

auto fibonacci(int count, int a = 1, int b = 1) -> int
{
    /*
    Fibonacci works for any two starting numbers, so let the user pick.
    The ratio will always approximate to the golden ratio!
    */
    if (count <= 0) throw InvalidInput();
    std::cout << a << ' ';
    switch (count) {
    case 1:  // Only called if N is 1 in main
        return a;
    case 2:  // Always called last (if N > 1)
        std::cout << b;
        return b;
    default:
        if (a + b < 0) throw Overflow(b);
        return fibonacci(--count, b, a + b);
    }
}

auto main() -> int
try {
    std::cout << "Enter a number N, for the Nth Fibonacci number\n";
    int N;
    std::cin >> N;
    fibonacci(N);
    std::cout << '\n';
}
catch (InvalidInput) {
    std::cout << "error: You have entered an invalid input for N\n";
}
catch (Overflow& e) {
    std::cout << e.number << "\nerror: Integer Overflow\n";
}