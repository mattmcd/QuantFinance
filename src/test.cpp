#include <iostream>
#include <Normals.hpp>

int main(void)
{
  double x;
  std::cout << "Enter a number: " << std::endl;
  std::cin >> x;

  std::cout << normpdf(x) << std ::endl;
  std::cout << inormcdf(normcdf(x)) << std ::endl;

  return 0;

}
