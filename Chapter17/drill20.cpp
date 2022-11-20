// allocate array of 10 ints 1, 2, 4, 8.. assign to p1

auto main() -> int
{
    int* p1 = new int[]{1,2,4,8,16,32,64,128,256,512};

    delete[] p1;
}