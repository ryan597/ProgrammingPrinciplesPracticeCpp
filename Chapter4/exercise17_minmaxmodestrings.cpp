#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool comparelen(const std::string& a, const std::string& b)
{
    return (a.size() < b.size());
}


std::string mode_string(const std::vector<std::string>& strings)
{
    std::string mode;
    int count{0};
    int largest{0};

    for (auto i: strings){
        count = std::count(strings.begin(), strings.end(), i);
        if (count > largest){
            mode = i;
            largest = count;
        }
    }
    return mode;
}


int main()
{
    std::vector<std::string> strings;
    std::string tmp;
    while (std::cin >> tmp){
        if (tmp.compare("|") == 0)
            break;
        else {
            strings.push_back(tmp);
        }
    }

    std::sort(strings.begin(), strings.end(), comparelen);
    std::cout << "The smallest string is:\t" << strings.front()
        << "\nThe largest string is:\t" << strings.back()
        << "\nThe string that appears most often is:\t" << mode_string(strings)
        << "\n";

    return 0;
}