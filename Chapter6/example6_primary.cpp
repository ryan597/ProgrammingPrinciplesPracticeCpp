// Define these to clear warnings. Main focus of this example is primary function
class Token {public: char kind; double value;};
class MissingBracket {};
class MissingPrimary {};
auto get_token() -> Token;
auto expression() -> double;

auto primary() -> double
{
    Token t = get_token();
    switch (t.kind) {
    case '(':
        {
            double d = expression();
            t = get_token();
            if (t.kind != ')') throw MissingBracket();
            return d;
        }
    case '8':
        return t.value;
    default:
        throw MissingPrimary();
    }
}