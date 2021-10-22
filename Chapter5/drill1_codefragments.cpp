#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

auto main() -> int
try {
    std::cout << "Success 1!\n";
    std::cout << "Success 2!\n";
    std::cout << "Success 3" << "!\n";
    std::cout << "Success 4!" << '\n';
    int res = 7; std::vector<int> v1(10); v1[5] = res; std::cout << "Success 5!\n";
    std::vector<int> v2(10); v2[5] = 7; if (v2[5] == 7) std::cout << "Success 6!\n";
    if (true) std::cout << "Success 7!\n"; else std::cout << "Fail!\n";
    bool c1 = false; if (!c1) std::cout << "Success 8!\n"; else std::cout << "Fail!\n";
    std::string s1 = "ape"; bool c2 = "fool" > s1; if (c2) std::cout << "Success 9!\n";
    std::string s2 = "ape"; if (s2 == "ape") std::cout << "Success 10!\n";
    std::string s3 = "ape"; if (s3 != "fool") std::cout << "Success 11!\n";
    std::string s4 = "ape"; if (s4 + "fool" == "apefool") std::cout << "Success 12!\n";
    std::vector<char> v3(5); for (int i = 0; i < v3.size(); ++i) ; std::cout << "Success 13!\n";
    std::vector<char> v4(5); for (int i = 0; i <= v4.size(); ++i) ; std::cout << "Success 14!\n";
    std::string s5 = "Success 15!\n"; for (int i = 0; i < s5.size(); ++i) std::cout << s5[i];
    if (true) std::cout << "Success 16!\n"; else std::cout << "Fail!\n";
    int x1 = 2000; char c3 = x1; if (c3 == (char) 2000) std::cout << "Success 17!\n";
    std::string s6 = "Success 18!\n"; for (int i =0; i < s6.size(); ++i) std::cout << s6[i];
    std::vector<int> v5; for (int i = 0; i <= v5.size(); ++i) ; std::cout << "Success 19!\n";
    int i1 = 0; int j1 = 9; while (i1 < 9) ++i1; if (j1 < i1) std::cout << "Success 20!\n";
    int x2 = 2; double d1 = 0.5 + 2 * x2; if (d1 == 2 * x2 + 0.5) std::cout << "Success 21!\n";
    std::string s7 = "Success 22!\n"; for (int i = 0; i < s7.size(); ++i) std::cout << s7[i];
    int i2 = 0; int j2 = 9; while (i2 < 10) ++i2; if (j2 < i2) std::cout << "Success 23!\n";
    int x3 = 4; double d2 = 5 / (x3 - 2); if (d2 == 5 / 2) std::cout << "Success 24!\n";
    std::cout << "Success 25!\n";
    std::getchar();
    return 0;
}
catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    std::getchar();
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n";
    std::getchar();
    return 2;
}