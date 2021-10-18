#include <iostream>
#include <string>
#include <vector>
#include <regex>

int main()
{
    std::vector<std::string> names;
    std::vector<int> scores;
    std::string tmp;

    std::regex re("[\\|0-9]");
    auto m_results = std::smatch{};

    while (std::cin >> tmp){
        if (tmp.compare("NoName0") == 0)
            break;
        else{
            std::regex_search(tmp, m_results, re);
            if (find(names.begin(), names.end(), m_results.prefix()) != names.end()){
                std::cout << "Duplicate Name\n";
            }
            else {
                names.push_back(m_results.prefix());
                scores.push_back(std::stoi(tmp.substr(m_results.position())));
            }
        }
    }
    for (int i = 0; i < names.size(); i++){
        std::cout << "Name: " << names[i] << "\tScore: " << scores[i] << "\n";
    }
    return 0;
}