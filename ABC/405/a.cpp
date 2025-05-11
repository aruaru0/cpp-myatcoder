#include <iostream>

int main()
{
    int r, x;
    std::cin >> r >> x;
    if (x == 1)
    {
        if (1600 <= r && r <= 2999)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    else
    {
        if (1200 <= r && r <= 2399)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}