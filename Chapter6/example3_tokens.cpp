class Token {
public:
    char kind;
    double value;
    // Overloading the constructors
    Token() = default;
    Token(char a) : kind(a) {};
    Token(int a): kind('8'), value(a) {};
    Token(double a): kind('8'), value(a) {};
    Token(char a, double b) : kind(a), value(b) {};
};

auto main() -> int
{
    return 0;
}