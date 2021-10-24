#include <iostream>
#include <math.h>

int main()
{
    int lower{1};
    int upper{100};
    int count{};
    bool correct{false};
    char responce;

    std::cout << "Think of an integer between 1 and 100\n";
    while (!correct){
        count++;
        std::cout << "Is the number between " << lower
            << " and " << upper - ceil((upper - lower)/ 2) << "?\t (y/n)\n";
        std::cin >> responce;

        if (responce == 'y'){
            upper = upper - ceil((upper - lower)/ 2);
        } else if (responce == 'n'){
            lower = upper - ceil((upper - lower)/ 2) + 1;
        }

        if (upper - lower == 1){
            std::cout << "Is the number " << lower << "?\n";
            count++;
            std::cin >> responce;
            if (responce == 'n'){
                std::cout << "Then it must be " << upper << "\n";
                count++;
            }
            correct = true;
            std::cout << "Number of guesses: " << count << '\n';
        }
    }
}