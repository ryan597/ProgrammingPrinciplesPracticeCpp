#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> words;
    for (std::string temp; std::cin >> temp;){
        words.push_back(temp);
    }
    std::cout << "Number of words: " << words.size() << "\n";

    std::sort(words.begin(), words.end());

    for (u_long i = 0; i < words.size(); i++){
        if (i == 0 || words[i-1] != words[i])  // is this a new word?
            std::cout << words[i] << "\n";
    }
}