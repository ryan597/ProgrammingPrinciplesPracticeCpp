#include <iostream>

// func to replace the chars in C style array with lowercase chars
auto to_lower(char* s) -> void
{
    int i{};
    while (true)
    {
        if (s[i] == '\0')
        {
            break;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] -= ('Z' - 'z');
        }
        ++i;
    }
}


// test
auto main() -> int
{
    std::string s;
    std::getline(std::cin, s);

    char c[s.size()];
    for (int i=0; i<s.size(); i++)
    {
        c[i] = s[i];
    }


    to_lower(c);

    for (auto i: c)
    {
        std::cout << i;
    }
    std::cout << '\n';

}