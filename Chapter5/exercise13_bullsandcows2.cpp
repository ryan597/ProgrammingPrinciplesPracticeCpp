#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>

class InvalidInput {};

auto generate_random_vec(int length = 4) -> std::vector<int>
{
    std::srand (time(nullptr));
    std::vector<int> vec(length);
    for (unsigned long i = 0; i < vec.size();) {
        int random = (std::rand() % 10);
        if (std::find(vec.begin(), vec.end(), random) == vec.end()) {
            vec[i] = random;
            i++;
        }
    }
    return vec;
}

auto check_user_guesses(const std::vector<int>& rand_vec, std::vector<int>& user_guess) -> bool
{
    for (auto& i: user_guess) {
        std::cin >> i;
    }
    if (std::cin.fail()) throw InvalidInput();
    int bulls {};  // Correct and in the right position
    int cows {};  // Correct but in the wrong position
    for (unsigned long i = 0; i < rand_vec.size(); i++) {
        if (user_guess[i] == rand_vec[i]) {
            bulls++;
        } else if (std::find(rand_vec.begin(), rand_vec.end(), user_guess[i]) != rand_vec.end()) {
            cows++;
        }
    }
    std::cout << bulls << " bulls and " << cows << " cows\n";
    if (bulls == 4) {
        return true;
    } else {
        return false;
    }
}

auto main() -> int
try {
    while(true) {
        std::cout << "Try and guess the 4 digit combination (x x x x)\n";
        int turns = 1;
        std::vector<int> user_guess(4);
        const std::vector<int> rand_vec = generate_random_vec();
        while(!check_user_guesses(rand_vec, user_guess)) {
            turns++;
        }
        std::cout << "You guessed correctly!\nIt took you " << turns << " guesses\n";
    }
}
catch (InvalidInput) {
    std::cout << "error: Bad input entered for guess\n";
}