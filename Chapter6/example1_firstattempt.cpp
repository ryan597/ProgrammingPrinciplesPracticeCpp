#include <iostream>

auto main() -> int
{
    std::cout << "Please enter expression (we handle + and -): ";
    int lval = 0;
    int rval = 0;
    char op;
    int res = 0;
    std::cin >> lval >> op >> rval;

    if (op == '+') {
        res = lval + rval;
    } else if (op == '-') {
        res = lval - rval;
    }

    std::cout << "Result: " << res << '\n';
    std::getchar();
}