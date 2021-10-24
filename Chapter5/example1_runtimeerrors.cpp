#include <iostream>

class NegativeLength {};

auto area(int length, int width) -> int
{
    if (length < 0 || width < 0) throw NegativeLength{};
    //  if (width < 0) throw NegativeLength{};
    return length * width;
}

auto framed_area(int x, int y) -> int
{
    return area(x-2, y-2);
}

auto main() -> int
try {
    // Negative value gives negatice area
    int x = -1;
    int y = 2;
    int z = 4;

    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);  // Subtraction of 2 gives negative area
    double ratio = double(area1) / area3;

    // use the variables to prevent warnings
    std::cout << area1 << '\n'
              << area2 << '\n'
              << area3 << '\n'
              << ratio << '\n';
}
catch (NegativeLength){
    std::cout << "ERROR: Negative length entered!\n";
}