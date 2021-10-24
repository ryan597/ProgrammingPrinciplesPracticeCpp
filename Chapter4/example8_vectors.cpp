#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(10);
    for (u_long i = 0; i < v.size(); ++i){
        v[i] = i;
        std::cout << v[i] << '\n';
    }

    // Modern C++ way of vector iteration
    for (auto i : v){
        std::cout << v[i] << '\n';
    }

    v.push_back(22);  // push back appends to the end of the vector
}