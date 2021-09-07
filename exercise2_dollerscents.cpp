#include <iostream>
#include <string>

int main()
{
    // Initialisation to 0
    float total_dollers{0};
    int total_cents{0};
    int pennies{0};         // 1 cent
    int nickles{0};         // 5 cents
    int dimes{0};           // 10 cents
    int quarters{0};        // 25 cents
    int half_dollers{0};    // 50 cents
    int dollers{0};         // 100 cents

    // User input
    std::cout << "How many pennies do you have?\n";
    std::cin >> pennies;
    std::cout << "How many nickles do you have?\n";
    std::cin >> nickles;
    std::cout << "How many dimes do you have?\n";
    std::cin >> dimes;
    std::cout << "How many quarters do you have?\n";
    std::cin >> quarters;
    std::cout << "How many half dollers do you have?\n";
    std::cin >> half_dollers;
    std::cout << "How many dollers do you have?\n";
    std::cin >> dollers;

    // Plurality
    std::string pennies_string = (pennies == 1) ? "penny" : "pennies";
    std::string nickles_string = (nickles == 1) ? "nickle" : "nickles";
    std::string dimes_string = (dimes == 1) ? "dime" : "dimes";
    std::string quarters_string = (quarters == 1) ? "quarter" : "quarters";
    std::string half_dollers_string = (half_dollers == 1) ? "half doller" : "half dollers";
    std::string dollers_string = (dollers == 1) ? "doller" : "dollers";

    // Totaling
    total_cents = pennies +
                  (nickles * 5) +
                  (dimes * 10) +
                  (quarters * 25) +
                  (half_dollers * 50) +
                  (dollers * 100);
    total_dollers = total_cents / 100.0;

    // Output totals
    std::cout << "You have " << pennies << " " << pennies_string
              << ".\nYou have " << nickles << " " << nickles_string
              << ".\nYou have " << dimes << " " << dimes_string
              << ".\nYou have " << quarters << " " << quarters_string
              << ".\nYou have " << half_dollers << " " << half_dollers_string
              << ".\nYou have " << dollers << " " << dollers_string
              << ".\nThe Value of all your coins is " << total_cents << " cents"
              << ".\nThe Value of all your coints is $" << total_dollers << ".\n";
}