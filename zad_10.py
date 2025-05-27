from math import *

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
    return 1 / (x**2 - 4*x + 3)

print("Using Simpson's method")
print("Integrating function: f(x) = 1 / (x^2 - 4x + 3)")

# Avoid the singularity at x=1 by splitting the interval
delta = 1e-3  # Wider margin to improve stability
a1, b1 = 0, 1 - delta
a2, b2 = 1 + delta, 2

eps = 1e-7

# Left side of the singularity
nseg = 2
int1_1 = simpson_rule(func, a1, b1, nseg)
int1_2 = simpson_rule(func, a1, b1, nseg * 2)

while abs(int1_1 - int1_2) > eps:
    nseg *= 2
    int1_1 = simpson_rule(func, a1, b1, nseg)
    int1_2 = simpson_rule(func, a1, b1, nseg * 2)

int_left = int1_2

# Right side of the singularity
nseg = 2
int2_1 = simpson_rule(func, a2, b2, nseg)
int2_2 = simpson_rule(func, a2, b2, nseg * 2)

while abs(int2_1 - int2_2) > eps:
    nseg *= 2
    int2_1 = simpson_rule(func, a2, b2, nseg)
    int2_2 = simpson_rule(func, a2, b2, nseg * 2)

int_right = int2_2

print("\nAnswer: I =", int_left + int_right)
print("Number of segments:", nseg * 2)