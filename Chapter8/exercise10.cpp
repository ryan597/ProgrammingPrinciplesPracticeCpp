#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


template <typename T>
auto maxv(std::vector<T>& vec) -> T
{
    return *std::max_element(vec.begin(), vec.end());
}

template <>
auto maxv(std::vector<std::string>& vec) -> std::string
{
    auto result = std::max_element(vec.begin(), vec.end(),
        [](const auto& a, const auto& b){return a.size() < b.size();});

    return *result;
}

auto main() -> int
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<double> v2{1.2, 2.454, 3234.0005, 4.34, -5};
    std::vector<std::string> v3{"Hello", "there", "General", "Kenobi"};

    auto m1 = maxv(v1);
    auto m2 = maxv(v2);
    auto m3 = maxv(v3);

    std::cout << "m1: "  << m1 << '\n'
              << "m2: "  << m2 << '\n'
              << "m3: "  << m3 << '\n';
}