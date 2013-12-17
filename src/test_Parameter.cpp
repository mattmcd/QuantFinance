#include "parameter.hpp"
#include <iostream>

int main(void) {
  Parameter p;
  p.set( "foo", 2 );
  p.set( "bar", 3.0 );

  std::cout << "Foo = " << p.get("foo") << std::endl;
  std::cout << "Bar = " << p.get("bar") << std::endl;

  return 0;
}
