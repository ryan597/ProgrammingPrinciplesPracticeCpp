#include <iostream>
#include <vector>
#include <string>

template <typename T>
auto print_vec(const std::string& label, const std::vector<T>& vec) -> void
{
    std::cout << label << ": {"  << vec[0];
    for (int i=1; i<vec.size(); i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << "}\n";
}

template <typename T>
auto reverse(const std::vector<T>& vec) -> std::vector<T>
{
    auto sz = vec.size();
    std::vector<T> rvec(vec.size());
    for (std::size_t i=0; i< sz; i++)
    {
        rvec[i] = vec[sz - i - 1];
    }
    return rvec;
}

template <typename T>
auto reverse_inplace(std::vector<T>& vec) -> void
{
    T tmp;
    std::size_t sz = vec.size();
    std::size_t stop = sz / 2;
    for (std::size_t i=0; i<stop; i++)
    {
        tmp = vec[i];
        vec[i] = vec[sz - i - 1];
        vec[sz - i - 1] = tmp;
    }
}


auto main() -> int
{
    std::vector<std::string> v1{"Kenobi", "General", "there", "Hello"};  // even
    std::vector<std::string> v2{"!", "Kenobi", "General", "there", "Hello"}; // odd

    auto r1 = reverse(v1);
    auto r2 = reverse(v2);

    print_vec("Reverse v1", r1);
    print_vec("Reverse v2", r2);

    reverse_inplace(v1);
    reverse_inplace(v2);

    print_vec("Reverse Inplace v1", v1);
    print_vec("Reverse Inplace v2", v2);
}