#include <iostream>
#include <string>
#include <vector>

/*
This is the same as exercise8 with the exception that value is now double and all derived variables
(eg. the vector) become double too
*/

// HEADER FILES
class SizeError {};
class InputError
{
public:
    // Pass by value and std::move() avoids extra copies over pass by reference
    InputError(std::string not_double) : value(std::move(not_double)) {};
    std::string value;
};


auto sum_doubles(const int N, const std::vector<double>& some_doubles) -> double
{
    double sum {};
    for (int i = 0; i < N; i++){
        std::cout << some_doubles[i] << " ";
        sum += some_doubles[i];
    }
    return sum;
}
// END OF HEADER FILES

auto main() -> int
try {
    std::cout << "Enter a number of values to sum\n";
    int N {};
    std::cin >> N;
    std::cout << "Enter some numbers (enter '|' to end input sequence)\n";
    double value;
    std::vector<double> some_doubles;

    while (std::cin >> value) {
        some_doubles.push_back(value);
    }
    std::cin.clear();
    std::string not_double;
    std::cin >> not_double;
    if (not_double.compare("|") == 0) {
        if (N > some_doubles.size()) throw SizeError();
        std::cout << "The sum of the first " << N << " values ( ";
        const double sum = sum_doubles(N, some_doubles);
        std::cout << ") is " << sum << '\n';
    } else {
        throw InputError(not_double);
    }
}
catch (SizeError) {
    std::cout << "error: Not enough values entered to sum\n";
    return 1;
}
catch (InputError &error) {
    std::cout << "error: Invalid input '" << error.value << "'\n";
    return 2;
}
