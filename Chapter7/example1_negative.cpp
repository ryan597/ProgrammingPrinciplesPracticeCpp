//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//


#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream() = default;   // make a Token_stream that reads from cin
    auto get() -> Token;      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer {0};     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

auto Token_stream::get() -> Token
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case '=':
    case 'x':
    case 'q':    // for "quit"
    case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
        return Token(ch);
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

auto expression() -> double;    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

auto factorial(int N) -> int
{
    int prod = 1;
    while (N >= 1) {
        prod *= N;
        --N;
    }
    return prod;
}

//------------------------------------------------------------------------------

// deal with numbers, factorials, and parentheses
auto primary() -> double
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
    {
        Token s = ts.get();
        if (s.kind == '!') { // check if we need to find factorial
            t.value = factorial((int) t.value);
        } else {
            ts.putback(s);
        }
        return t.value;  // return the number's value
    }
    case '-':
    {
        return - primary();
    }
    case '+':
    {
        return primary();
    }
    default:
        error("primary expected");
        return t.value;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
auto term() -> double
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '!':
            left = factorial((int) left);
            t = ts.get();
            break;
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
            {
                error("divide by zero");
            }
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
auto expression() -> double
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

auto main() -> int
try
{
    cout << "Welcome to our simple calculator\n"
         << "Please enter expressions using floating point numbers.\n"
         << "Available operations: Addition +, Subtraction -, Multiplication *, Division /\n"
         << "Enter x to exit the program, and = to print the result.\n";
    while (cin) {
        double val = expression();
        Token t = ts.get();

        if (t.kind == 'x') break; // 'x' for exit
        if (t.kind == '=')        // '=' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
