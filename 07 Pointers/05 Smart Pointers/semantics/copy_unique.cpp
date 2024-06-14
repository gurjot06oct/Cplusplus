#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<int> ptr1(new int(42));
    std::unique_ptr<int> ptr2 = ptr1; // Error: std::unique_ptr does not support copy semantics
    return 0;
}
