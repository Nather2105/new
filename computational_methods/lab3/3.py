from math import exp

# Метод простої ітерації із допоміжною функцією g(x)
def simple_iteration(lambda_0, eps):
    lambda_prev = lambda_0
    lambda_next = g(lambda_prev)
    while abs(lambda_next - lambda_prev) >= eps:
        lambda_prev = lambda_next
        lambda_next = g(lambda_prev)
    return lambda_next

def g(x):
    return (15 - 7*(exp(x)-1))/ (10*exp(x)+7)


# Метод Ньотона зі допоможними функціями f(x), df(x)
def newton_method(lambda0, eps):
    lambda_prev = lambda0
    lambda_new = lambda_prev - f(lambda_prev) / df(lambda_prev)
    while abs(lambda_new - lambda_prev) > eps:
        lambda_prev = lambda_new
        lambda_new = lambda_prev - f(lambda_prev) / df(lambda_prev)
    return lambda_new

def f(x):
    return 10 * x * exp(x) + 7 * (exp(x) - 1) - 15

def df(x):
    return 10 * x * exp(x) + 10 * exp(x) + 7 * exp(x)

 
epsilon = 0.001
lambda_zero = 1.0

lambda1 = simple_iteration(lambda_zero, epsilon)
print(f"Simple method of iteration: {lambda1}")

lambda2 = newton_method( lambda_zero, epsilon)
print(f"Newton's method: {lambda2}")
