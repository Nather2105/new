import numpy as np

# Вхідні дані
A = np.array([[3.141, -0.515, 0.321, -0.321],
              [1.444, -2.112, 0.413, 5.934],
              [0.311, -3.541, 14.241, 0.709],
              [0.341, 9.542, -1.647, 0.342]])

b = np.array([3.104, 5.679, 12.031, 8.578])

# Перетворення системи рівнянь
D = np.diag(np.diag(A))
R = A - D

# Початкове наближення
x = np.zeros_like(b)

# Точність
epsilon1 = 0.01
epsilon2 = 0.0001

# Ітераційний процес
iterations1 = 0
iterations2 = 0
error = np.inf

while error > epsilon1:
    x_new = np.dot(np.linalg.inv(D), b - np.dot(R, x))
    error = np.linalg.norm(x_new - x, ord=np.inf)
    x = x_new
    iterations1 += 1

    if error <= epsilon2:
        break

    iterations2 += 1

# Вивід результатів
print("Розв'язок:")
print(x)
print("Кількість ітерацій для точності ε1:", iterations1)
print("Кількість ітерацій для точності ε2:", iterations2)
