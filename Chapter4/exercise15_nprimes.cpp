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
    std::cout << "Enter a number of primes to search for\n";
    u_long N;
    std::cin >> N;

    std::vector<int> primes = {2};
    std::cout << "Adding 2 to list of primes\n";
    for (int x = 1; primes.size() < N; x++){
        if (isprime(x, primes)){
            primes.push_back(x);
            std::cout << "Adding " << x << " to the list of primes\n";
        }
    }
    for (auto x: primes){
        std::cout << x << " ";
    }
    std::cout << "\n";
}