#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double func(double x) {
    return sin(x) / x;
}

double trapezoid_rule(double (*func)(double), double a, double b, int nseg) {
    double dx = (b - a) / nseg;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < nseg; ++i) {
        sum += func(a + i * dx);
    }
    return sum * dx;
}

int main() {
    cout << "Using the trapezoidal method" << endl;
    cout << "Integrating function: f(x) = sin(x) / x" << endl;

    double a = 1.0, b = 10.0;
    int nseg = 2;
    double eps = 1e-7;

    cout << "a = " << a << "; b = " << b << "; eps = " << eps << endl;

    double int_1 = trapezoid_rule(func, a, b, nseg);
    nseg *= 2;
    double int_2 = trapezoid_rule(func, a, b, nseg);

    while (abs(int_1 - int_2) > eps) {
        int_1 = int_2;
        nseg *= 2;
        int_2 = trapezoid_rule(func, a, b, nseg);
    }

    cout << "\nResult: I = " << int_2 << endl;
    cout << "Number of subdivisions: " << nseg << endl;

    return 0;
}