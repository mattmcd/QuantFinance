#include <Wrapper.hpp>
#include <PayOff.hpp>
#include <memory>
#include <iostream>

int main()
{
  auto callPtr = Wrapper<AbstractPayOff>( new PayOffCall(50));
  PayOffPut put(50);
  auto putPtr = Wrapper<AbstractPayOff>(put);
  PayOffCall call2(50);
  
  std::cout << (*callPtr)(55) << std::endl;  // 5
  std::cout << (*putPtr)(43) << std::endl;  // 7

  std::cout << std::endl;

  // Look at ptr addressing
  // These should all be on the stack next to each other
 std::cout << &callPtr << std::endl;
 std::cout << &put << std::endl;
 std::cout << &putPtr << std::endl;  
  std::cout << &call2 << std::endl;
 
  std::cout << std::endl;
 std::cout << &(*callPtr) << std::endl;  
 std::cout << &(*putPtr) << std::endl;  


  return 0;
}