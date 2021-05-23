#include <iostream>
#include <cassert>

#include "RingBuffer.h"

int main()
{
    RingBuffer<int> rbuf(10);
    rbuf.push_back(4);
    rbuf.push_back(2);
    rbuf.push_back(3);
    assert(*(rbuf.end() - 2) == 2);
    return 0;
}
