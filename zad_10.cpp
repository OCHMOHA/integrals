#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return 1.0 / (x * x - 4 * x + 3);
}

double simpson(double (*f)(double), double a, double b, int nseg) {
    if (nseg % 2 == 1) nseg++;
    double h = (b - a) / nseg;
    double result = f(a) + f(b);
    for (int i = 1; i < nseg; i += 2)
        result += 4 * f(a + i * h);
    for (int i = 2; i < nseg; i += 2)
        result += 2 * f(a + i * h);
    return result * h / 3.0;
}

int main() {
    double eps = 1e-7;
    double delta = 1e-3;
    double a1 = 0, b1 = 1 - delta;
    double a2 = 1 + delta, b2 = 2;

    int nseg = 2;
    double int1 = simpson(func, a1, b1, nseg);
    double int2 = simpson(func, a1, b1, nseg * 2);

    while (fabs(int1 - int2) > eps) {
        nseg *= 2;
        int1 = simpson(func, a1, b1, nseg);
        int2 = simpson(func, a1, b1, nseg * 2);
    }

    double left = int2;

    nseg = 2;
    int1 = simpson(func, a2, b2, nseg);
    int2 = simpson(func, a2, b2, nseg * 2);

    while (fabs(int1 - int2) > eps) {
        nseg *= 2;
        int1 = simpson(func, a2, b2, nseg);
        int2 = simpson(func, a2, b2, nseg * 2);
    }

    double right = int2;

    cout << "Integral 10 Result: " << left + right << endl;
    cout << "Segments used: " << nseg * 2 << endl;
    return 0;
}