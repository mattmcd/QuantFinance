#include <PayOff.hpp>
#include <iostream>

int main()
{
	PayOffCall call(50.0);

    std::cout << call(45.0) << std::endl;  // Expect 0.0
    std::cout << call(55.0) << std::endl;  // Expect 5.0

    return 0;
}