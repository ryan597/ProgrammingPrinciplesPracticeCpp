#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>

class Name_value
{
public:
    std::string name;
    int value;
};

auto main() -> int
{
    std::vector<Name_value> nameval_vec;
    std::string tmp;

    std::regex re("[\\|0-9]");
    auto m_results = std::smatch{};

    std::cout << "Enter names and values together (eg. John52 James21)\n";

    while (std::cin >> tmp){
        if (tmp.compare("NoName0") == 0)
            break;
        else{
            std::regex_search(tmp, m_results, re);
            auto search_it = find_if(nameval_vec.begin(), nameval_vec.end(),
                [&m_results](const Name_value& obj) {return obj.name == m_results.prefix();});

            if (search_it != nameval_vec.end()){
                std::cout << "Duplicate Name\n";
            }
            else {
                std::string name = m_results.prefix();
                int score = std::stoi(tmp.substr(m_results.position()));
                nameval_vec.push_back({name, score});
            }
        }
    }
    for (auto pair: nameval_vec){
        std::cout << "Name: " << pair.name << "\tScore: " << pair.value << "\n";
    }
    return 0;
}