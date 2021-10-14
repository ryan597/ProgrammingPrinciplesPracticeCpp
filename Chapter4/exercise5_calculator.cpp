#include <iostream>

int main()
{
    double a;
    double b;
    char op;
    std::cout << "Please enter two numbers with an operation in between eg. 3 + 5\n";
    std::cin >> a >> op >> b;

    switch (op){
        case '+':
            std::cout << "The sum of " << a << " and " << b << " is\t" << a + b << "\n";
            break;
        case '-':
            std::cout << "The subtraction of " << a << " and " << b << " is\t" << a - b << "\n";
            break;
        case '*':
            std::cout << "The multiplication of " << a << " and " << b << " is\t" << a * b << "\n";
            break;
        case '/':
            std::cout << "The division of " << a << " and " << b << " is\t" << a / b << "\n";
            break;
        default:
            std::cout << "Invalid input. Try again.\n";
            break;
    }
    return 0;
}