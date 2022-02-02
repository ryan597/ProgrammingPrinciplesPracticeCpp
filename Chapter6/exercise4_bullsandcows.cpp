#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>


auto generate_random_vec(int length = 4) -> std::vector<char>
{
    std::srand (time(nullptr));
    std::vector<char> vec(length);
    for (unsigned long i = 0; i < vec.size();) {
        char random = (std::rand() % 26) + 97;  // lower case letter a starts at 97 and wrap at 26 numbers later
        // Dont include the same character twice
        if (std::find(vec.begin(), vec.end(), random) == vec.end()) {
            vec[i] = random;
            i++;
        }
    }
    return vec;
}

auto check_user_guesses(const std::vector<char>& rand_vec, std::vector<char>& user_guess) -> bool
{
    for (auto& i: user_guess) {
        std::cin >> i;
    }
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
{
    const std::vector<char> rand_vec = generate_random_vec();
    std::cout << "Try and guess the 4 letter combination (x x x x)\n";
    int turns = 1;
    std::vector<char> user_guess(4);
    while(!check_user_guesses(rand_vec, user_guess)) {
        turns++;
    }
    std::cout << "You guessed correctly!\nIt took you " << turns << " guesses\n";
}