#ifndef PAYOFF_HPP
#define PAYOFF_HPP

// Interface for PayOff for options dependent on spot price only

// Notes:
// 1.  Constructors must be non-virtual i.e. must have an implementation.  
//     For the base class we use the default 'do nothing' {}.
// 2.  Destructors must be virtual as subclasses may need to do
//     subclass specific cleanup.  Each subclass must have an implementation
//     of its destructor.  Here we use the default 'do nothing' {}.
// 3.  The base class operator() is pure virtual, A.K.A. abstract in 
//     MATLAB.
// 4.  The operator() does not change the state of the PayOff 
//     so is declared const.  This is a very basic equivalent of
//     a MATLAB value class in that we can call the operator() method
//     from multiple functions without worrying about changing the PayOff.
class AbstractPayOff {
    // Abstract base class for PayOffs
    public:
        AbstractPayOff(){} 
        virtual ~AbstractPayOff(){}
        virtual double operator()(double Spot) const = 0;
    private:
};

// Payoffs for specific option types.

class PayOffCall : public AbstractPayOff {
    public:
        PayOffCall( double Strike_ );
        virtual ~PayOffCall(){}
        virtual double operator()(double Spot) const;
    private:
        double Strike;
};

class PayOffPut : public AbstractPayOff {
    public:
        PayOffPut( double Strike_ );
        virtual ~PayOffPut(){}
        virtual double operator()(double Spot) const;
    private:
        double Strike;
};

#endif
