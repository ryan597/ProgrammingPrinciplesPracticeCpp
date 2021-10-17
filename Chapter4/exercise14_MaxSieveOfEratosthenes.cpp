#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int max;
    std::cout << "Enter the max number to search to\n";
    std::cin >> max;
    std::vector<int> marked;
    std::vector<int> primes;
    for (int p = 2; p <= max; p++){
        if (std::find(marked.begin(), marked.end(), p) == marked.end()){
            primes.push_back(p);
            std::cout << "Adding " << p << " to the list of primes\n";
            for (int i = 2; i * p <= max; i++){
                marked.push_back(i*p);
            }
        }
    }
    std::cout << "Number of primes found: " << primes.size() << "\n";
    return 0;
}