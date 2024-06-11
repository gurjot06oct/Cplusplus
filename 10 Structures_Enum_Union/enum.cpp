#include <iostream>

enum Weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    Weekday today = MONDAY;
    std::cout << Weekday::FRIDAY << std::endl; // 4
    if (today == SATURDAY || today == SUNDAY)
    {
        std::cout << "It's a weekend!" << std::endl;
    }
    else
    {
        std::cout << "It's a weekday." << std::endl;
    }

    return 0;
}
