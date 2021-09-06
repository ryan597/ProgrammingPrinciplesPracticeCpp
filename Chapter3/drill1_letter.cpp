#include <iostream>
#include <string>

int main()
{
    std::string first_name;
    std::string friend_name;
    char friend_sex {0};
    int age {0};
    std::cout << "Enter the name of the person you want to write to: ";
    std::cin >> first_name;
    std::cout << "Enter the name of a friend: ";
    std::cin >> friend_name;
    std::cout << "Friends sex (m if male, f if female): ";
    std::cin >> friend_sex;
    std::cout << "Enter age of recipient: ";
    std::cin >> age;

    if (age <= 0 || age >= 110)
        std::cout << "You're kidding!\n";

    std::cout << "Dear " << first_name << ",\n"
              << "  How are you? I am fine. I miss you.\n"
              << "Have you seen " << friend_name << " recently?\n";
    std::cout << "If you see " << first_name << " please ask ";
    if (friend_sex == 'm')
        std::cout << "him ";
    if (friend_sex == 'f')
        std::cout << "her ";
    std::cout << "to call me\n"
              << "I hear you just had a birthday and you are " << age
              << " years old.";
    if (age < 12)
        std::cout << "Next year you will be " << age+1 << ".\n";
    if (age == 17)
        std::cout << "Next year you will be able to vote.\n";
    if (age > 70)
        std::cout << "I hope you are enjoying retirement.\n";
    std::cout << "Yours sincerely,\n\n\nRyan\n";
}