#include "polynomial.h"

int main() {
    Polynomial p1, p2;
    std::cin >> p1;
    std::cout << p1 << std::endl;
    std::cin >> p2;
    std::cout << p2 << std::endl << std::endl;
    std::cout << p1 + p2 << std::endl;
    std::cout << p1 * p2 << std::endl;
    std::cout << p1 / 7.5 << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    return 0;
}
