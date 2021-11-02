#include <iostream>

class NoOpperand {};
class InvalidExpression {};

auto main() -> int
{
    std::cout << "Please enter expression (we handle +, -, * and /)"
              << "\nAdd an x to end expression (eg. 1+2*3x): ";
    int lval = 0;
    int rval = 0;
    std::cin >> lval;
    if (!std::cin) throw NoOpperand();

    for (char op; std::cin >> op; ) {
        if (op != 'x') std::cin >> rval;
        if (!std::cin) throw NoOpperand();
        switch (op) {
        case '+':
            lval += rval;
            break;
        case '-':
            lval -= rval;
            break;
        case '*':
            lval *= rval;
            break;
        case '/':
            lval /= rval;
            break;
        default:
            std::cout << "Result: " << lval << '\n';
            std::getchar();
            return 0;
        }
    }
    throw InvalidExpression();
}