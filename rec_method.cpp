#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return sin(x) / x;
}

double rectangle_rule(double (*func)(double), double a, double b, int nseg, double frac) {
    double dx = (b - a) / nseg;
    double sum = 0.0;
    double xstart = a + frac * dx;
    for (int i = 0; i < nseg; ++i) {
        sum += func(xstart + i * dx);
    }
    return sum * dx;
}

int main() {
    cout << "Using the rectangle method" << endl;
    cout << "Integrating function: f(x) = sin(x) / x" << endl;

    double a = 1.0;
    double b = 10.0;
    int nseg = 10000;
    double frac = 0.5;

    cout << "a = " << a << "; b = " << b << "; frac = " << frac << endl;
    cout << "Number of subdivisions: " << nseg << endl;

    double result = rectangle_rule(func, a, b, nseg, frac);
    cout << "\nResult: I = " << result << endl;

    return 0;
}