#include <iostream>
#include <vector>
#include <string>

// create a vector of fibonacci numbers and print using function from ex2.

auto print_vec(const std::string& label, const std::vector<int>& vec) -> void
{
    std::cout << label << ": {"  << vec[0];
    for (int i=1; i<vec.size(); i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << "}\n";
}

auto fibonacci(int x, int y, std::vector<int>& v, int n) -> void
{
    v.reserve(n);
    v.emplace_back(x);
    v.emplace_back(y);
    n -= 2;
    int nxt{};
    while (n > 0)
    {
        --n;
        nxt = x + y;
        v.emplace_back(nxt);
        x = y;
        y = nxt;
    }
}

// test func
auto main() -> int
{
    int x{0};
    int y{1};
    std::vector<int> v;
    int n{50};  // why not break it, int overflow

    fibonacci(x, y, v, n);
    print_vec("Fibonacci", v);
}