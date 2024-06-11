#include <iostream>

int main()
{
    float a = 0.1f + 0.1f + 0.1f;
    if (a == 0.3f)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal: " << a << std::endl;
    }
    return 0;
}
