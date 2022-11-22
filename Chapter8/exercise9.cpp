#include <iostream>
#include <vector>
#include <string>

auto calculate(const std::vector<double>& price, const std::vector<double>& weight) -> double
{
    if (price.size() != weight.size()) return 0.0;
    double result{};
    for (int i=0; i<price.size(); i++)
    {
        result = price[i] * weight[i];
    }
    return result;
}

auto main() -> int
{
    const std::vector<double> price{1, 2.3, 4, 5, 5, 5.6};
    const std::vector<double> weight{10, 2, 42, 5.1, 5.3, 5.6};

    double result = calculate(price, weight);
    std::cout << "Result: " << result << '\n';
}