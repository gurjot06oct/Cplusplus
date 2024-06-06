#include <iostream>

#define PI 3.14159
#define SQUARE(x) (x * x)

int main()
{
    double circleArea = PI * 5 * 5;
    std::cout << "Circle Area: " << circleArea << std::endl;

    int squareOfThree = SQUARE(3);
    std::cout << "Square of 3: " << squareOfThree << std::endl;

    return 0;
}
