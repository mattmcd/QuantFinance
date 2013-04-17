#include <GBMPath.cpp>
#include <vector>
#include <iostream>

int main() 
{
  double Mu = 0.08;
  double Sigma = 0.17;
  int Days = 100;

  GBMPath pathGen( Days, Mu, Sigma );
  std::vector<double> price(Days);

  pathGen.getPath( price );

  for( auto p : price ) {
    std::cout << p << " ";
  }
  std::cout << std::endl;
  
  return 0;
}