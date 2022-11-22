#include <iostream>
#include <vector>
#include <string>


auto print_until_s(const std::vector<std::string>& v, std::string quit) -> void
{
    for (auto s: v)
    {
        if (s == quit) return;
        std::cout << s << '\n';
    }
}

auto print_until_ss(const std::vector<std::string>& v, std::string quit) -> void
{
    bool twice{false};
    for (auto s: v)
    {
        if (s == quit)
        {
            if (twice) return;
            twice = true;
        }
        std::cout << s << '\n';
    }
}


auto main() -> int
{
    const std::vector<std::string> v{"Hello", "there", "General", "Kenobi", "Hello", "there", "General", "Kenobi"};

    print_until_s(v, "General");
    std::cout << "\n\n";
    print_until_ss(v, "General");
}