#ifndef VANILLAOPTION_HPP
#define VANILLAOPTION_HPP

#include <PayOff.hpp>
#include <memory>

// VanillaOption containing
// the time to Expiry (double, in years) and an 
// AbstractPayOff object.
// NB: since we're storing an Abstract class we 
// need to store either a reference or a pointer in
// order to have constant storage space allocated
// in this object, independent of the subclass type.

class VanillaOption 
{
    public:
        VanillaOption(double Expiry_,  AbstractPayOff& PayOff_) 
            : Expiry(Expiry_), PayOff(PayOff_)  {};
        ~VanillaOption() {};
        double getExpiry( ) const { return Expiry; } ;
        double getPayOff(double spot) const {
            return PayOff(spot);
        };
    private:
        const AbstractPayOff& PayOff;
        const double Expiry;
};

#endif