#include <iostream>

int main()
{
    int b, r;
    std::cin >> b >> r;

    int h = 30 - b;
    int w = 30 - r;

    std::cout << h * w << std::endl;
}