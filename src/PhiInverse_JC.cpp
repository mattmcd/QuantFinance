#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

double LogOnePlusX(double x);
double NormalCDFInverse(double p);
double RationalApproximation(double t);
void demo();

// compute log(1+x) without losing precision for small values of x
double LogOnePlusX(double x)
{
    if (x <= -1.0)
    {
        std::stringstream os;
        os << "Invalid input argument (" << x 
           << "); must be greater than -1.0";
        throw std::invalid_argument( os.str() );
    }

    if (fabs(x) > 1e-4)
    {
        // x is large enough that the obvious evaluation is OK
        return log(1.0 + x);
    }

    // Use Taylor approx. log(1 + x) = x - x^2/2 with error roughly x^3/3
    // Since |x| < 10^-4, |x|^3 < 10^-12, relative error less than 10^-8

    return (-0.5*x + 1.0)*x;
}

double RationalApproximation(double t)
{
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) / 
               (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}

double NormalCDFInverse(double p)
{
    if (p <= 0.0 || p >= 1.0)
    {
        std::stringstream os;
        os << "Invalid input argument (" << p 
           << "); must be larger than 0 but less than 1.";
        throw std::invalid_argument( os.str() );
    }

    // See article above for explanation of this section.
    if (p < 0.5)
    {
        // F^-1(p) = - G^-1(p)
        return -RationalApproximation( sqrt(-2.0*log(p)) );
    }
    else
    {
        // F^-1(p) = G^-1(1-p)
        return RationalApproximation( sqrt(-2.0*log(1-p)) );
    }
}

void demo()
{
    std::cout << "\nShow that the NormalCDFInverse function is accurate at \n"
              << "0.05, 0.15, 0.25, ..., 0.95 and at a few extreme values.\n\n";

    double p[] =
    {
        0.0000001,
        0.00001,
        0.001,
        0.05,
        0.15,
        0.25,
        0.35,
        0.45,
        0.55,
        0.65,
        0.75,
        0.85,
        0.95,
        0.999,
        0.99999,
        0.9999999
    };

    // Exact values computed by Mathematica.
    double exact[] =
    {
        -5.199337582187471,
        -4.264890793922602,
        -3.090232306167813,
        -1.6448536269514729,
        -1.0364333894937896,
        -0.6744897501960817,
        -0.38532046640756773,
        -0.12566134685507402,
         0.12566134685507402,
         0.38532046640756773,
         0.6744897501960817,
         1.0364333894937896,
         1.6448536269514729,
         3.090232306167813,
         4.264890793922602,
         5.199337582187471
    };

    double maxerror = 0.0;
    int numValues = sizeof(p)/sizeof(double);
    std::cout << "p, exact CDF inverse, computed CDF inverse, diff\n\n";
    std::cout << std::setprecision(7);
    for (int i = 0; i < numValues; ++i)
    {
        double computed = NormalCDFInverse(p[i]);
        double error = exact[i] - computed;
        std::cout << p[i] << ", " << exact[i] << ", " 
                  << computed << ", " << error << "\n";
        if (fabs(error) > maxerror)
            maxerror = fabs(error);
    }

    std::cout << "\nMaximum error: " << maxerror << "\n\n";
}

int main()
{
    demo();
    return 0;
}
