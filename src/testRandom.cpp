// ==============================================================
// 
//       Filename:  testRandom.cpp
// 
//    Description:  Test C++11 Random
// 
//        Version:  1.0
//        Created:  02/03/13 09:04:26
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#include <random>
#include <iostream>
#include <functional>
#include <valarray>

int main() 
{
  // std::default_random_engine generator;
  std::mt19937 generator;
  std::uniform_int_distribution<int> distribution(1,6);
  std::normal_distribution<double> normdist(0.0, 1.0);
  std::uniform_real_distribution<double> unifdist(0.0, 1.0);

  // Bind the generator to the first argument of distribution so that
  // we can call with rng() instead of dist(gen).
  auto rng = std::bind( unifdist, generator );

  for( int i=0; i<25; ++i ) {
    std::cout << rng() << " ";
  }
  std::cout << std::endl;
  
  // Now create a random matrix
  std::valarray<double> v(100);
  for (int i=0; i < v.size(); i++ ) {
    v[i] = rng();
  }



  return 0;
}
