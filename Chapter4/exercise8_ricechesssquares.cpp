#include <iostream>
#include <cmath>

int squaresforX(int x)
{
    int squares{};
    int totalgrains{};
    while (totalgrains < x){
        totalgrains += pow(2, squares);
        squares++;
        std::cout << "squares " << squares << "\t grains " << totalgrains << "\n";
    }
    return squares;
}



int main()
{
    int forthousand = squaresforX(1000);
    int formillion = squaresforX(1000000);
    int forbillion = squaresforX(1000000000);

    std::cout << "Number of squares for X grains of rice:\n"
        << "1000\t" << forthousand << "\n"
        << "1,000,000\t" << formillion << "\n"
        << "1,000,000,000\t" << forbillion << "\n";
    return 0;
}