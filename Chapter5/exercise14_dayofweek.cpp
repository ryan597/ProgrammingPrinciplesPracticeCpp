#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

/*
 * This is probably my 'ugliest' code so far... But short of writing a multi-key map which also implements the
 * .begin(), and end() iterators, it's the best I could do at this stage.
 */

auto check_synonym(std::string* day, const std::map<std::string, std::vector<std::string>>& day_synonyms) -> bool
{
    for (auto [key, value]: day_synonyms) {
        if (std::find(value.begin(), value.end(), *day) != value.end()) {
            *day = key;  // true if the synonym is found, change day to the proper key
            return true;
        }
    }
    return false;
}

auto main() -> int
{
    std::map<std::string, std::vector<int>> day_value_pairs {
        {"Monday", {}},
        {"Tuesday", {}},
        {"Wednesday", {}},
        {"Thursday", {}},
        {"Friday", {}},
        {"Saturday", {}},
        {"Sunday", {}}
    };

    const std::map<std::string, std::vector<std::string>> day_synonyms {
        {"Monday", {"Mon", "monday", "mon"}},
        {"Tuesday", {"Tue", "tuesday", "tue"}},
        {"Wednesday", {"Wed", "wednesday", "wed"}},
        {"Thursday", {"Thur", "thursday", "thur"}},
        {"Friday", {"Fri", "friday", "fri"}},
        {"Saturday", {"Sat", "saturday", "sat"}},
        {"Sunday", {"Sun", "sunday", "sun"}}
    };
    std::cout << "Enter a day of the week (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday)\n"
              << "along with a value for that day. Repeat days and values as many times as you like.\n"
              << "To terminate input, press Ctrl+D (on Linux) or enter a character for the value\n";
    int rejected = 0;
    int value;
    std::string day;
    while (true) {
        std::cin >> day >> value;
        if (std::cin.fail()) break;
        if (day_value_pairs.find(day) != day_value_pairs.end()) {
            day_value_pairs[day].push_back(value);
        } else if (check_synonym(&day, day_synonyms)) {  // if day is a synonym, change day to be the proper key and return true
            day_value_pairs[day].push_back(value);
        } else {
            rejected++;
        }
    }

    for (auto [day, vec]: day_value_pairs) {
        std::cout << day << ": ( ";
        int total = 0;
        for (auto value: vec) {
            std::cout << value << ' ';
            total += value;
        }
        std::cout << ") = \t\t" << total << '\n';
    }
    std::cout << "\nNumber of rejected inputs: " << rejected << '\n';
}