#ifndef PARAMETER_H
#define PARAMETER_H

#include <unordered_map>
#include <string>

class Parameter {
  // Simple dictionary of parameters
  public:
    void set(std::string name, double value) {
      std::pair<std::string,double> v( name, value);
      params.insert( v);
    }
    double get( std::string name ) {
      auto it = params.find( name );
      return it->second;
    }

  private:
    std::unordered_map<std::string,double> params;
};

#endif
