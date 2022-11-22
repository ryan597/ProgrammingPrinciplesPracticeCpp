#include <iostream>
#include <vector>
#include <string>

template <typename T>
auto print_vec(const std::vector<T>& vec) -> void
{
    for (auto i: vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

auto chars_in_string(const std::vector<std::string>& vec) -> std::vector<int>
{
    std::vector<int> result(vec.size());
    for (std::size_t i=0; i<vec.size(); i++)
    {
        result[i] = vec[i].length();
    }
    return result;
}

// test func
auto main() -> int
{
    const std::vector<std::string> v1{"Hello", "there", "General", "Kenobi"};  // 5, 5, 7, 6
    const std::vector<std::string> v2{"One does not simply", "walk into Mordor..."};  // 19, 19

    const auto r1 = chars_in_string(v1);
    const auto r2 = chars_in_string(v2);

    print_vec(r1);
    print_vec(r2);
}