#include <GBMPath.hpp>

#include <cmath>

GBMPath::GBMPath( int Days_, double Mu_, double Sigma_ ) :
  Days(Days_), Mu(Mu_), Sigma(Sigma_) {}

GBMPath::GBMPath( int Days_ ) : Days(Days_), Mu(0.08), Sigma(0.17) {}

void GBMPath::getPath( std::vector<double> &v) 
{
  // Reset the vector
  v[0] = 100.0;
  auto mu = Mu/252.0; // Daily return
  auto sigma = Sigma/std::sqrt(252.0);
  auto rng = std::bind(normdist, generator);
  for (int i = 1; i < v.size(); i++ ) {
    v[i] = v[i-1]*(1 + mu + sigma*rng());
  }

  return;
}