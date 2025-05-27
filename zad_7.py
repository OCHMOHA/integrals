from math import sqrt

def simpson_rule(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx = (b - a) / nseg
    total = func(a) + func(b)
    for i in range(1, nseg, 2):
        total += 4 * func(a + i * dx)
    for i in range(2, nseg, 2):
        total += 2 * func(a + i * dx)
    return total * dx / 3

def func(x):
    return x**5 / sqrt(4 - x**2)

print("Using Simpson's method")
print("Integrating function: f(x) = x^5 / sqrt(4 - x^2)")

a = 0
b = 2 - 1e-6
nseg = 2
eps = 1e-7

int_1 = simpson_rule(func, a, b, nseg)
int_2 = simpson_rule(func, a, b, nseg * 2)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = simpson_rule(func, a, b, nseg)
    int_2 = simpson_rule(func, a, b, nseg * 2)

print("\nAnswer: I =", int_2, "\nNumber of segments:", nseg * 2)