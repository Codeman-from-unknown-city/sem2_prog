#include <iostream>

#include "RingBuffer.h"

int main()
{
    RingBuffer<int> rbuf(10);
    rbuf.push_back(2);
    rbuf.push_back(3);
    std::cout << *(rbuf.end() - 1) << std::endl;
    return 0;
}