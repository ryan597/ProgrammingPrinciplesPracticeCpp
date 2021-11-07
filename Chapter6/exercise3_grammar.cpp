#include <iostream>
#include <string>
#include <algorithm>
#include <map>

class Word
{
private:
    std::map<const std::string, const char> parts_of_speech {
        {"birds", 'n'},
        {"fish", 'n'},
        {"c++", 'n'},
        {"and", 'c'},
        {"or", 'c'},
        {"but", 'c'},
        {"rules", 'v'},
        {"fly", 'v'},
        {"swim", 'v'},
        {"the", 'a'}
    };
    auto find_type(std::string word) -> char
    {
        for_each(word.begin(), word.end(), [](char& c) {
            c = tolower(c);});
        return parts_of_speech[word];
    }

public:
    std::string value;
    char type;
    Word(int word) {value = word; type = '-';}
    Word(std::string word)
    {
        value = word;
        type = find_type(word);
    }
};

auto sentence() -> bool
{
    // Sentence: Noun-Verb-(Conjunction-Sentence...) or Article-Noun-Verb-(Conjunction-Sentence...)
    std::string temp;
    Word old_word(0) ;
    while (true) {
        std::cin >> temp;
        if (temp.compare(".") == 0) return true;
        Word new_word(temp);

        switch (new_word.type) {
        case 'a':
            if (old_word.type != '-') return false;
            break;
        case 'c':
            if (old_word.type != 'v' && old_word.type != 'n') return false;
            return sentence();
        case 'n':
            if (old_word.type != '-' && old_word.type != 'a') return false;
            break;
        case 'v':
            if (old_word.type != 'n') return false;
            break;
        default:
            std::cout << "Invalid input\n";
            return false;
        }
        old_word = new_word;
    }
    return true;
}


auto main() -> int
{
    std::cout << "Enter a sentence, termined by a space and fullstop .\n";
    while (sentence()) {  // terminate the program after an invalid sentence
        std::cout << "OK\n";
    }
    std::cout << "not OK\n";
    return 0;
}