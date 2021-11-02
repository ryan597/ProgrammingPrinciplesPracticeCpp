// Define these to clear warnings. Main focus of this example is term function
class ZeroDivision {};
class Token {public: char kind; double value;};
auto get_token() -> Token;
auto primary() -> double;

auto term() -> double
{
    double left = primary();
    Token t = get_token();
    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) throw ZeroDivision();
            left /= primary();
            t = get_token();
            break;
        }
        /*case '%':
            left %= primary();
            t = get_token();
            break;*/
        default:
            return left;
        }
    }
}
