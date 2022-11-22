#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct summary
{
    double min{};
    double max{};
    double mean{};
    double median{};
};

auto operator<< (std::ostream& os, const summary& s) -> std::ostream&
{
    os << "Min: " << s.min << '\n'
       << "Max: " << s.max << '\n'
       << "Mean: " << s.mean << '\n'
       << "Median: " << s.median << '\n';
    return os;
}

auto small_and_large(std::vector<double> vec) -> summary
{
    auto it_min = std::min_element(vec.begin(), vec.end());
    auto it_max = std::max_element(vec.begin(), vec.end());

    double mean{};
    for (auto i: vec)
    {
        mean += i;
    }

    std::size_t sz = vec.size();
    mean = mean / sz;

    double median{};
    if (sz % 2 == 0)
    {
         median = (vec[sz/2 - 1] + vec[sz/2]) / 2;
    }
    else
    {
        median = vec[sz/2];
    }
    return {*it_min, *it_max, mean, median};
}


// test func
auto main() -> int
{
    std::vector<double> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> vec2{1.003, 22.3, 3.543, 4.4444, 5.54, .6, .766, 8.90, 9.45, 10.1};

    summary res1 = small_and_large(vec1);
    summary res2 = small_and_large(vec2);

    std::cout << res1 << '\n' << res2;

}