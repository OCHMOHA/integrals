#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return log(x) / (x * x);
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
    double a = 1, b = 1000; // large enough upper limit
    int nseg = 2;
    double eps = 1e-7;

    double int1 = simpson(func, a, b, nseg);
    double int2 = simpson(func, a, b, nseg * 2);

    while (fabs(int1 - int2) > eps) {
        nseg *= 2;
        int1 = simpson(func, a, b, nseg);
        int2 = simpson(func, a, b, nseg * 2);
    }

    cout << "Integral 8 Result: " << int2 << endl;
    cout << "Segments used: " << nseg * 2 << endl;
    return 0;
}