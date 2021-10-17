#include <iostream>
#include <cmath>

int largestgrainsint()
{
    int squares{};
    int totalgrains{};
    while (squares < 64){
        totalgrains += pow(2, squares);
        squares++;
        std::cout << "squares " << squares << "\t grains " << totalgrains << "\n";
    }
    return totalgrains;
}

double largestgrainsdouble()
{
    int squares{};
    double totalgrains{};
    while (squares < 100){
        totalgrains += pow(2, squares);
        squares++;
        std::cout << std::fixed << "squares " << squares << "\t grains " << totalgrains << "\n";
    }
    return totalgrains;
}



int main()
{
    // The 32bit integer will fail on the 32nd square and wraps around to a negative
    // using unsigned int will cause it to wrap around to 0
    int grainsint = largestgrainsint();
    double grainsdouble = largestgrainsdouble();
    return 0;
}