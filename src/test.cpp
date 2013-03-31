#include <iostream>
#include <Normals.hpp>

int main(void)
{
  double x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  // Should equal 0
  std::cout << "inormcdf(0.5) = " << inormcdf(0.5) << std::endl;
  // Should = 0.5
  std::cout << "normcdf(0) = " << normcdf(0) << std::endl;

  std::cout << "normpdf(" << x << ") = " << normpdf(x) << std ::endl;

  std::cout << "inormcdf(normcdf(" << x << ")) = " 
            << inormcdf(normcdf(x)) << std ::endl;

  return 0;

}
