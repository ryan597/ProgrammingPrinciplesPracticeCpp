#include <iostream>
#include <string>
#include <vector>

/*
This is the same as exercise 8 as I already deal with not integer inputs.
*/

// HEADER FILES
class SizeError {};
class InputError {
public:
    // Pass by value and std::move() avoids extra copies over pass by reference
    InputError(std::string not_integer) : value(std::move(not_integer)) {}
    std::string value;
};


auto sum_ints(const int N, const std::vector<int>& some_integers) -> int
{
    int sum {};
    for (int i = 0; i < N; i++){
        std::cout << some_integers[i] << " ";
        sum += some_integers[i];
    }
    return sum;
}
// END OF HEADER FILES

auto main() -> int
try {
    std::cout << "Enter a number of integers to sum\n";
    int N {};
    std::cin >> N;
    std::cout << "Enter some integers (enter '|' to end input sequence)\n";
    int value;
    std::vector<int> some_integers;

    while (std::cin >> value) {
        some_integers.push_back(value);
    }
    std::cin.clear();
    std::string not_int;
    std::cin >> not_int;
    if (not_int.compare("|") == 0) {
        if (N > some_integers.size()) throw SizeError();
        std::cout << "The sum of the first " << N << " values ( ";
        const int sum = sum_ints(N, some_integers);
        std::cout << ") is " << sum << '\n';
    } else {
        throw InputError(not_int);
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
