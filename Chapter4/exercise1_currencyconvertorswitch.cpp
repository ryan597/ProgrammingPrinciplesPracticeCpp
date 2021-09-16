#include <iostream>

int main()
{
    double amount_from{0};
    double amount_to{0};
    const double factor_yen2dollers{0.0091};
    const double factor_eur2dollers{1.18};
    const double factor_pou2dollers{1.38};
    const double factor_kro2dollers{0.12};
    char currency {'0'};

    std::cout << "Please enter an amount of currency followed by the currency\n"
              << "(e - Euros, p - Pounds, y - Yen, k - Kroner)\n";
    std::cin >> amount_from >> currency;

    switch (currency){
        case 'e':
            amount_to = factor_eur2dollers * amount_from;
            std::cout << "€" << amount_from << " is $" << amount_to << "\n";
            break;
        case 'p':
            amount_to = factor_pou2dollers * amount_from;
            std::cout << "£" << amount_from << " is $" << amount_to << "\n";
            break;
        case 'y':
            amount_to = factor_yen2dollers * amount_from;
            std::cout << amount_from << " Yen" << " is $" << amount_to << "\n";
            break;
        case 'k':
            amount_to = factor_kro2dollers * amount_from;
            std::cout << amount_from << " Kroner" << " is $" << amount_to << "\n";
            break;
        default:
            std::cout << "Currency not detected\nExiting.";
            break;
    }
}