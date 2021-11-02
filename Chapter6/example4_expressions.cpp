// Define these to clear warnings. Main focus of this example is expression function
class Token {public: char kind; double value;};
auto get_token() -> Token;
auto term() -> double;

auto expression() -> double
{
    double left = term();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = get_token();
            break;
        case '-':
            left -= term();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}

auto main() -> int
{
    return 0;
}