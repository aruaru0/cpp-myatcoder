#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (a > 0 && b > 0)
    {
        std::cout << "Yes" << std::endl;
    }
    else if (a < 0 && b < 0)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}