#include <iostream>
#include <vector>

auto print_vec(const std::string& label, const std::vector<int>& vec) -> void
{
    std::cout << label << ": {"  << vec[0];
    for (int i=1; i<vec.size(); i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << "}\n";
}

auto reverse(const std::vector<int>& vec) -> std::vector<int>
{
    auto sz = vec.size();
    std::vector<int> rvec(vec.size());
    for (std::size_t i=0; i< sz; i++)
    {
        rvec[i] = vec[sz - i - 1];
    }
    return rvec;
}

auto reverse_inplace(std::vector<int>& vec) -> void
{
    int tmp{};
    std::size_t sz = vec.size();
    std::size_t stop = sz / 2;
    for (std::size_t i=0; i<stop; i++)
    {
        tmp = vec[i];
        vec[i] = vec[sz - i - 1];
        vec[sz - i - 1] = tmp;

        //std::swap(vec[i], vec[sz - i - 1]);
    }
}


auto main() -> int
{
    std::vector<int> v1{1, 2, 4, 8, 16, 32, 64};  // odd num of elements
    std::vector<int> v2{1, 2, 4, 8, 16, 32, 64, 128};  // even num of elements

    auto r1 = reverse(v1);
    auto r2 = reverse(v2);

    print_vec("Reverse v1", r1);
    print_vec("Reverse v2", r2);

    reverse_inplace(v1);
    reverse_inplace(v2);

    print_vec("Reverse Inplace v1", v1);
    print_vec("Reverse Inplace v2", v2);
}