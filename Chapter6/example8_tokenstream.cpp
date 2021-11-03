#include <iostream>

class BufferFull {};
class BadToken {};
class Token {public: char kind; double value;};

class TokenStream {
public:
    TokenStream();
    auto get() -> Token;
    auto putback(Token t) -> void;
private:
    bool full {false};
    Token buffer;
};

auto TokenStream::putback(Token t) -> void
{
    if (full) throw BufferFull();
    buffer = t;
    full = true;
}

auto TokenStream::get() -> Token
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;

    switch (ch) {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token{'8', val};
    }
    default:
        throw BadToken();
    }
}