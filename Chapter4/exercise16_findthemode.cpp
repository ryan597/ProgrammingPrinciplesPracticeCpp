#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int mode = -1;
    int largest = 0;
    int count{};
    std::vector<int> numbers;
    int x;
    std::cout << "Enter integer numbers. Enter something other than an integer to terminate\n";
    while(std::cin >> x){
        numbers.push_back(x);
    }

    for (auto i: numbers){
        count = std::count(numbers.begin(), numbers.end(), i);
        if (count > largest){
            largest = count;
            mode = i;
        }
    }
    std::cout << "The mode is: " << mode << "\nIt appears " << largest << " times\n";
    return 0;
}