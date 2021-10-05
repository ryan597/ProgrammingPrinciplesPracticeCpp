#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<double> temps;
    for (double temp; std::cin >> temp;){
        temps.push_back(temp);
    }
    double sum{0};
    for (int x: temps){
        sum += x;
    }

    std::cout << "Average temperature: " << sum / temps.size() << "\n";

    std::sort(temps.begin(), temps.end());
    std::cout << "Median temperature: " << temps[temps.size()/2] << "\n";
}