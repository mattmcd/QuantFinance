#include <PayOff.hpp>

PayOffCall :: PayOffCall( double Strike_ ) : Strike(Strike_) {}

double PayOffCall :: operator()(double Spot) const {
	double payOff = Spot-Strike;
	return payOff >= 0 ? payOff : 0.0;
}

PayOffCall* PayOffCall :: clone() const {
    return new PayOffCall(*this);
}

PayOffPut :: PayOffPut( double Strike_ ) : Strike(Strike_) {}

double PayOffPut :: operator()(double Spot) const {
	double payOff = Strike - Spot;
	return payOff >= 0 ? payOff : 0.0;
}

PayOffPut* PayOffPut :: clone() const {
    return new PayOffPut(*this);
}