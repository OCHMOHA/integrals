#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double func(double x) {
    return sin(x) / x;
}

double simpson_rule(double (*func)(double), double a, double b, int nseg) {
    if (nseg % 2 != 0) nseg++; 
    double dx = (b - a) / nseg;
    double sum = func(a) + 4 * func(a + dx) + func(b);
    int half = nseg / 2;

    for (int i = 1; i < half; ++i) {
        sum += 2 * func(a + 2 * i * dx) + 4 * func(a + (2 * i + 1) * dx);
    }
    return sum * dx / 3;
}

int main() {
    cout << "Using Simpson's method" << endl;
    cout << "Integrating function: f(x) = sin(x) / x" << endl;

    double a = 1.0, b = 10.0;
    int nseg = 2;
    double eps = 1e-7;

    cout << "a = " << a << "; b = " << b << "; eps = " << eps << endl;

    double int_1 = simpson_rule(func, a, b, nseg);
    nseg *= 2;
    double int_2 = simpson_rule(func, a, b, nseg);

    while (abs(int_1 - int_2) > eps) {
        int_1 = int_2;
        nseg *= 2;
        int_2 = simpson_rule(func, a, b, nseg);
    }

    cout << "\nResult: I = " << int_2 << endl;
    cout << "Number of subdivisions: " << nseg << endl;

    return 0;
}