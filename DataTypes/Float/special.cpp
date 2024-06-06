#include <iostream>
#include <cmath> // for INFINITY and NAN

int main()
{
    float inf = INFINITY;
    float nan = NAN;
    std::cout << "Infinity: " << inf << std::endl;
    std::cout << "NaN: " << nan << std::endl;

    if (std::isinf(inf))
    {
        std::cout << "inf is infinity" << std::endl;
    }
    if (std::isnan(nan))
    {
        std::cout << "nan is not a number" << std::endl;
    }
    return 0;
}
