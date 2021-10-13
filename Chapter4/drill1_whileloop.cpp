#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    double temp{};
    double smallest{10000000000};
    double largest{-10000000000};
    std::string unit;
    double cm2meter{1/ 100};
    double inch2meter{1 / (2.54 * 100)};
    double feet2meter{12 / (2.54 * 100)};
    std::vector<double> values;

    bool cond {false};

    std::setprecision(51);
    std::cout << "Enter a value and unit (cm, m, in, ft)\n";
    while(!cond){
        if (std::cin >> temp >> unit){
            std::cout << "\nValue entered: " << temp << " " << unit << "\n";

            if (unit == "cm")
                temp *= cm2meter;
            if (unit == "in")
                temp *= inch2meter;
            if (unit == "ft")
                temp *= feet2meter;

            values.push_back(temp);

            if (temp > largest){
                largest = temp;
                std::cout << "The largest value so far is: " << largest << "m\n";
            }
            else if (temp < smallest){
                smallest = temp;
                std::cout << "The smallest value so far is: " << smallest << "m\n";
            }
        }
        else {
            std::cin.clear();    // reset the fail state
            if (std::cin.peek() == '|') {
                std::cout << "Found end of input marker |\n";
                std::sort(values.begin(), values.end());
                for (auto i: values){
                    std::cout << i << "\n";
                }
                cond = true;
            } else {
                std::cout << "Invalid input!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}