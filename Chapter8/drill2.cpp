
auto swap_v(int a, int b) -> void
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

auto swap_r(int& a, int& b) -> void
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//auto swap_cr(const int& a, const int& b) -> void  // wont compile: reassigning const reference
//{
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//}

auto main() -> int
{
    int x = 7;
    int y = 9;
    swap_v(x, y);
    swap_r(x, y);
//    swap_cr(x, y);
    swap_v(7, 9);
//    swap_r(7, 9);  // non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
//    swap_cr(7, 9);

    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
//    swap_r(cx, cy);  // binding reference of type ‘int&’ to ‘const int’ discards qualifiers
//    swap_cr(cx, cy);

    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
//    swap_r(dx, dy);  // cannot bind non-const lvalue reference of type ‘int&’ to a value of type ‘double’
//    swap_cr(dx, dy);
    swap_v(7.7, 9.9);
//    swap_r(7.7, 9.9);  // cannot bind non-const lvalue reference of type ‘int&’ to a value of type ‘double’
//    swap_cr(7.7, 9.9);

}