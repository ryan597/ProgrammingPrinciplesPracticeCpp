#include <iostream>
#include <cmath>
#include <vector>

bool isprime(int x, const std::vector<int>& primes)
{
    bool prime {true};
    for (auto i: primes){
        if (x == 1) {prime = false;}
        if (x % i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    int max{};
    std::cout << "Enter a max number to search up to\n";
    std::cin >> max;

    std::vector<int> primes = {2};
    std::cout << "Adding 2 to list of primes\n";
    for (int x = 1; x <= max; x++){
        if (isprime(x, primes)){
            primes.push_back(x);
        }
    }
    std::cout << "\nNumber of primes found: " << primes.size() << "\n";
}