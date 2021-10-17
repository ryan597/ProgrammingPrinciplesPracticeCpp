#include <iostream>
#include <stdlib.h>
#include <string>

std::string findwinner(int user, int computer)
{
    std::string winner{};
    switch (user){
        case 0:
            if (computer == 0) {winner = "DRAW";}
            if (computer == 1) {winner = "Computer";}
            if (computer == 2) {winner = "User";}
            break;
        case 1:
            if (computer == 0) {winner = "User";}
            if (computer == 1) {winner = "DRAW";}
            if (computer == 2) {winner = "Computer";}
            break;
        case 2:
            if (computer == 0) {winner = "Computer";}
            if (computer == 1) {winner = "User";}
            if (computer == 2) {winner = "DRAW";}
            break;
        case 5:
            std::cout << "EXITING\n";
            return "";
        default:
            std::cout << "Invalid input\n";
            break;
    }
    return winner;
}

int main()
{
    int userplayed{};
    std::cout << "Enter your guess \nrock: 0, paper: 1, scissors: 2, EXIT: 5\n";
    while (userplayed != 5){
        int computerplayed = std::rand() % 3;
        std::cin >> userplayed;
        if (std::cin.good())
            std::cout << "Winner is\t" << findwinner(userplayed, computerplayed) << "\n";
        else{
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return 0;
}