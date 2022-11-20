#include <iostream>
// find out how much memory before memory exhaustion

auto main() -> int
{
    long mem_count{};
    while(true)
    {
        auto p = new char[1000000];
        mem_count += sizeof(char[1000000]);
        std::cout << "Memory allocated: " << mem_count << " bytes\n";
    }
}


// Once all RAM was used, program began moving everything to the swap partition
// After swap was filled too, program slowed along with all other programs on computer.
// It actually didn't fail, though it might have been killed after some time (OS was probably terminating other background processes first).
// On my computer, the RAM (16GB) and the SWAP (20GB) were filled (other programs taking 2.35GB and 1.68GB respectively).