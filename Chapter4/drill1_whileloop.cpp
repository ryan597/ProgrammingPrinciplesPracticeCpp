#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
    double a;
    double b;
    bool cond {false};

    std::setprecision(51);
    while(!cond){
        if (std::cin >> a >> b){
            if (a == b)
                std::cout << "The numbers are equal\n";
            else{
                std::cout << "The smaller value is: " << ((a < b )? a : b);
                std::cout << "\nThe larger value is: " << ((a > b)? a : b);
                std::cout << '\n';
                if ( abs(a - b) < 0.01){
                    std::cout << "The numbers are almost equal\n";
                }
            }
        }
        else {
            std::cin.clear();    // reset the fail state
            if (std::cin.peek() == '|') {
                std::cout << "Found end of input marker |\n";
                cond = true;
            } else {
                std::cout << "Invalid input!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}