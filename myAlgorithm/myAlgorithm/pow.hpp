#include <cmath>

double absPow(double x, unsigned int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    if (n % 2 == 0)
        return absPow(x, n / 2) * absPow(x, n / 2);
    else
        return absPow(x, n / 2) * absPow(x, n / 2)*x;
}

double myPow(double x, int n)
{
    double result = absPow(x, std::abs(n));
    if (n < 0)
        return 1 / result;
    else
        return result;
}