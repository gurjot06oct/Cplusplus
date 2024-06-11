#include <iostream>
#include <cfloat> // for DBL_MIN and DBL_MAX

int main()
{
    std::cout << "The smallest positive normalized double value (DBL_MIN): " << DBL_MIN << std::endl;
    std::cout << "The largest positive double value (DBL_MAX): " << DBL_MAX << std::endl;

    return 0;
}
