// Definitions to get rid of warnings, TokenStream to be implemented later.
// Main focus of this example is the putback of unused tokens in expression and term
class ZeroDivision {};
class MissingBracket {};
class MissingPrimary {};
class Token {public: char kind; double value;};
class TokenStream {public: auto get() -> Token; auto putback() -> void;} ts;
auto expression() -> double;

auto primary() -> double
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') throw MissingBracket();
            return d;
        }
    case '8':
        return t.value;
    default:
        throw MissingPrimary();
    }
}

auto term() -> double
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) throw ZeroDivision();
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback();
            return left;
        }
    }
}

auto expression() -> double
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback();
            return left;
        }
    }
}

