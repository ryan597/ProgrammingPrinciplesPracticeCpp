#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

void print_median(std::vector<double> temps);

int main()
{
    double sum{};
    std::vector<double> temps;
    std::cout << "Enter temperatures seperated by a space \nAfter pressing enter, end sequence with Ctrl+D\n";

    for (double temp; std::cin >> temp; ){
        temps.push_back(temp);
    }
    for (int x: temps){
        sum += x;
    }
    std::cout << "Average temperature: " << sum / temps.size() << "\n";
    print_median(temps);

}

void print_median(std::vector<double> temps)
{
    std::sort(temps.begin(), temps.end());
    std::cout << "Median Temperature: ";
    if (temps.size() % 2 == 1){
        std::cout << temps[ceil(temps.size() / 2)];
    } else if (temps.size() % 2 == 0){
        double v1 = temps[temps.size() / 2];
        double v2 = temps[(temps.size() / 2) - 1];
        std::cout << (v1 + v2) / 2.0;
    }
    std::cout << '\n';
}
