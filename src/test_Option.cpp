#include <PayOff.hpp>
#include <VanillaOption.hpp>
#include <memory>
#include <iostream>

int main()
{
    auto callPayOff = PayOffCall(50.0);
    double expiry = 0.5; // Years

    auto theOption = VanillaOption(expiry, callPayOff );

    // Test option methods
    std::cout << theOption.getExpiry() << std::endl;
    std::cout << theOption.getPayOff( 55.0 ) << std::endl;

    return 0;
}