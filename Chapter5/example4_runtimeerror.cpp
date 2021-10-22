#include <iostream>
#include <string>
#include <stdexcept>

auto error(std::string s1) -> void;
auto error(std::string s1, std::string s2) -> void;

auto main() -> int
try{
    // Some program
    int i;
    std::cin >> i;
    if (!std::cin) error("Bad input for i\n");
    return 0;
}
catch (std::runtime_error& e){
    std::cerr << "Runtime error: " << e.what() << "\n";
    std::getchar();
    return 1;
}
catch (std::exception& e){
    std::cerr << "Error: " << e.what() << "\n";
    std::getchar();
    return 1;
}
catch (...){
    std::cerr << "Oops: unknown exception!\n";
    std::getchar();
    return 2;
}


auto error(std::string s1) -> void
{
    throw std::runtime_error(s1);
}

auto error(std::string s1, std::string s2) -> void
{
    throw std::runtime_error(s1+ s2);
}
