#include <iostream>
#include <string>
#include <vector>

int string_to_int(std::string x)
{
    int y;
    std::vector<std::string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (x.length() > 1){
        auto ittr = find(digits.begin(), digits.end(), x);
        if (ittr == digits.end())
            std::cout << "Not a valid spelling\n";
        else{
            int index = std::distance(digits.begin(), ittr);
            y = index;
        }
    }
    else
        y = std::stoi(x);
    return y;
}

int main()
{
    std::string a;
    std::string b;
    char op;

    std::cout << "Please enter two integers with an operation in between eg. three + 5\n";
    std::cin >> a >> op >> b;

    int x = string_to_int(a);
    int y = string_to_int(b);

    switch (op){
        case '+':
            std::cout << "The sum of " << x << " and " << y << " is\t" << x + y << "\n";
            break;
        case '-':
            std::cout << "The subtraction of " << x << " and " << y << " is\t" << x - y << "\n";
            break;
        case '*':
            std::cout << "The multiplication of " << x << " and " << y << " is\t" << x * y << "\n";
            break;
        case '/':
            std::cout << "The division of " << x << " and " << y << " is\t" << x / y << "\n";
            break;
        default:
            std::cout << "Invalid input. Try again.\n";
            break;
    }
    return 0;
}