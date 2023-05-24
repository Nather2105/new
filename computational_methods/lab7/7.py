
# import matplotlib.pyplot as plt
# import numpy as np

# def solve_boundary_problem(N):
#     a = np.zeros(N-1)
#     b = np.zeros(N-1)
#     c = np.zeros(N-1)
#     x = np.linspace(0.5, 1, N+1)
#     h = (x[-1] - x[0]) / N
    
#     # Конструюємо тридіагональну матрицю
#     for i in range(N-1):
#         a[i] = 2 + 2*h + (4*h**2/x[i+1])
#         b[i] = -1
#         c[i] = -1
    
#     # Крайові умови
#     alpha = np.zeros(N-1)
#     beta = np.zeros(N-1)
#     alpha[0] = c[0] / a[0]
#     beta[0] = (2 * h**2) / a[0]
    
#     for i in range(1, N-1):
#         alpha[i] = c[i] / (a[i] - b[i]*alpha[i-1])
#         beta[i] = (2 * h**2 - b[i]*beta[i-1]) / (a[i] - b[i]*alpha[i-1])
    
#     y = np.zeros(N+1)
#     y[N] = (2 * h**2 + beta[N-2]) / (1 - alpha[N-2])
    
#     for i in range(N-1, 0, -1):
#         y[i] = alpha[i-1] * y[i+1] + beta[i-1]
    
#     return y
# def max_deviation(y1, y2):
#     deviation = np.abs(y1 - y2)
#     max_dev = np.max(deviation)
#     return max_dev

# # Розмір сітки
# N = 10

# # Розв'язок на сітці N=10
# y_10 = solve_boundary_problem(N)

# # Розв'язок на сітці N=20
# y_20 = solve_boundary_problem(2*N)


# # Виведення результатів
# print("Розв'язок на сітці N=10:")
# print(y_10)
# print()
# print("Розв'язок на сітці N=20:")
# print(y_20)

# # Порівняння розв'язків на сітці
# max_dev = max_deviation(y_10[:N+1], y_20[:N+1])

# # Виведення результатів
# print()
# print("Максимальне відхилення між розв'язками на сітках N=10 і N=20:", max_dev)


# # Побудова графіку
# x = np.linspace(0.5, 1, N+1)
# x_2N = np.linspace(0.5, 1, 2*N+1)

# plt.plot(x, y_10, label='N=10')
# plt.plot(x_2N, y_20, label='N=20')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.title('Approximate Solutions')
# plt.legend()
# plt.grid(True)
# plt.show()

import matplotlib.pyplot as plt
import numpy as np

def solve_boundary_problem(N):
    a = np.zeros(N-1)
    b = np.zeros(N-1)
    c = np.zeros(N-1)
    x = np.linspace(0.5, 1, N+1)
    h = (x[-1] - x[0]) / N
    
    # Конструюємо тридіагональну матрицю
    for i in range(N-1):
        a[i] = 2 + 2*h + (4*h**2/x[i+1])
        b[i] = -1
        c[i] = -1
    
    # Крайові умови
    alpha = np.zeros(N-1)
    beta = np.zeros(N-1)
    alpha[0] = c[0] / a[0]
    beta[0] = (2 * h**2) / a[0]
    
    for i in range(1, N-1):
        alpha[i] = c[i] / (a[i] - b[i]*alpha[i-1])
        beta[i] = (2 * h**2 - b[i]*beta[i-1]) / (a[i] - b[i]*alpha[i-1])
    
    y = np.zeros(N+1)
    y[N] = (2 * h**2 + beta[N-2]) / (1 - alpha[N-2])
    
    for i in range(N-1, 0, -1):
        y[i] = alpha[i-1] * y[i+1] + beta[i-1]
    
    return y

# Розмір сітки
N = 10

# Розв'язок на сітці N=10
y_10 = solve_boundary_problem(N)

# Розв'язок на сітці N=20
y_20 = solve_boundary_problem(2*N)

# Побудова графіку
x = np.linspace(0.5, 1, N+1)
x_2N = np.linspace(0.5, 1, 2*N+1)

plt.plot(x, y_10, label='N=10')
plt.plot(x_2N, y_20, label='N=20')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Approximate Solutions')
plt.legend()
plt.grid(True)
plt.show()
