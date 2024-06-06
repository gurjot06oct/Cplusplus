#include <iostream>
#include <cfloat> // for FLT_MIN and FLT_MAX

int main()
{
    std::cout << "The smallest positive normalized float value (FLT_MIN): " << FLT_MIN << std::endl;
    std::cout << "The largest positive float value (FLT_MAX): " << FLT_MAX << std::endl;

    return 0;
}
