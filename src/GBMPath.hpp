#ifndef GBMPATH_HPP
#define GBMPATH_HPP

#include <vector>
#include <random>
#include <functional>

class GBMPath {
  public:
    // Constructor with default parameters
    GBMPath( int Days );
    // Constructor with all parameters specified
    GBMPath( int Days, double Mu_, double Sigma_);
    
    // Put a vector representing the path into vector v
    void getPath( std::vector<double> &v );

  private:
    const int Days;
    const double Mu; // Return
    const double Sigma; // Volatility

    const std::mt19937 generator;  // Mersene twister generator
    const std::normal_distribution<double> normdist; // Normal distribution
};

#endif