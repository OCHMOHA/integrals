from math import *

def simpson_rule(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx = (b - a) / nseg
    total = func(a) + 4 * func(a + dx) + func(b)
    nseg = int(nseg / 2)
    for i in range(1, nseg):
        total += 2 * func(a + (2 * i) * dx) + 4 * func(a + (2 * i + 1) * dx)
    return total * dx / 3

def func(x):
    alpha = 0.5  # You can change α here
    return x**alpha * log(x)

# Parameters
eps_shift = 1e-7
a = eps_shift       # avoid division by 0 at x = 0
b = 1
nseg = 2
eps = 1e-7

# Integration loop
int_1 = simpson_rule(func, a, b, nseg)
int_2 = simpson_rule(func, a, b, nseg * 2)
while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = simpson_rule(func, a, b, nseg)
    int_2 = simpson_rule(func, a, b, nseg * 2)

print("Result I =", int_2)
print("Number of segments:", nseg * 2)