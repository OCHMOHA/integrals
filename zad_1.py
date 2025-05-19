# Simpson's method with specified accuracy
def simpson_rule(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx = (1.0 * (b - a)) / nseg
    total = func(a) + 4 * func(a + dx) + func(b)
    nseg = int(nseg / 2)
    for i in range(1, nseg):
        total += 2 * func(a + (2 * i) * dx) + 4 * func(a + (2 * i + 1) * dx)
    return total * dx / 3

from math import log, pow

print("Using Simpson's Method")
print("Integrating the function: f(x) = x^a * ln(x)")

# Parameters for the integral
a_value = 2       # Parameter 'a' in x^a * ln(x), must be > 0
a = 1e-6          # Left limit of integration (use a small number instead of 0 to avoid ln(0))
b = 1             # Right limit of integration
eps = 1e-6        # Desired accuracy
nseg = 2          # Initial number of segments

# Define the function to integrate
def func(x):
    if x == 0:
        return 0  # Protect against log(0)
    return pow(x, a_value) * log(x)

# Compute the integral with the desired precision
int_1 = simpson_rule(func, a, b, nseg)
nseg *= 2
int_2 = simpson_rule(func, a, b, nseg)

while abs(int_1 - int_2) > eps:
    int_1 = int_2
    nseg *= 2
    int_2 = simpson_rule(func, a, b, nseg)

print("Result:", int_2)
print("Number of segments:", nseg)