#include <iostream>
#include <vector>

int main()
{
    std::vector<double> distances;
    double smallest{};
    double largest{};
    double sum{};
    double mean{};

    std::cout << "Enter distances between cities\nAfter pressing Enter, end thesequence with Ctrl+D\n";
    for (double i; std::cin >> i; ){
        distances.push_back(i);
        sum += i;
    }
    std::sort(distances.begin(), distances.end());
    mean = sum / distances.size();
    smallest = distances.front();
    largest = distances.back();
    std::cout << "Smallest distance: " << smallest
        << "\nLargest distance: " << largest
        << "\nMean distance: " << mean;
}