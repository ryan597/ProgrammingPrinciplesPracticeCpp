#include <iostream>
#include <vector>

auto main() -> int
{
    std::vector<double> temps;

    for (double temp; std::cin >> temp; ){
        temps.push_back(temp);
    }

    /* In the book ``PPP using C++'', Bjarne completly re-writes the main function to sovle the problem of bad initialisation.
     * I think its easier to just change to initialisation of high and low to be the first elements of temps rather than his
     * "Impossiblely" high and low values.
    */
    double sum = 0;
    double high_temp = temps[0];
    double low_temp = temps[0];

    for (int x: temps){
        if (x > high_temp) high_temp = x;
        if (x < low_temp) low_temp = x;
        sum += x;
    }
    std::cout << "High temperature: " << high_temp << "\n";
    std::cout << "Low temperature: " << low_temp << "\n";
    std::cout << "Average temperature: " << sum / temps.size() << "\n";
}