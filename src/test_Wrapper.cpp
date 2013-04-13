#include <Wrapper.hpp>
#include <PayOff.hpp>
#include <memory>
#include <iostream>

int main()
{
  auto callPtr = Wrapper<AbstractPayOff>( new PayOffCall(50));
  PayOffPut put(50);
  auto putPtr = Wrapper<AbstractPayOff>(put);
  
  std::cout << (*callPtr)(55) << std::endl;  // 5
  std::cout << (*putPtr)(43) << std::endl;  // 7

  return 0;
}