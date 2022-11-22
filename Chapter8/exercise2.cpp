#include <iostream>
#include <vector>
#include <string>

// write a function that prints a vector of ints to cout with two arguments, a label and the vector of ints
auto print_vec(const std::string& label, const std::vector<int>& vec) -> void
{
    std::cout << label << ": {"  << vec[0];
    for (int i=1; i<vec.size(); i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << "}\n";
}


// test the func
auto main() -> int
{
    const std::vector<int> vec{1, 2, 4, 8, 16};
    const std::string label = "Example Vector";

    print_vec(label, vec);

}