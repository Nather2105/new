import numpy as np
import matplotlib.pyplot as plt

X = np.arange(2006, 2016, dtype=np.float64)  # Вхідні дані для осі x (роки)
Y = np.array([54512, 79955, 101659, 103396, 117343, 126236, 116454, 135065, 142079, 126308], dtype=np.float64)  # Вхідні дані для осі y (значення)

def phi(x_array, k):
    return x_array ** k  # Функція для обчислення phi(x) = x^k

def GetCoefficients(x, y, n):
    matrix = np.zeros((n, n))  # Ініціалізуємо матрицю нулями
    b = np.zeros(n)  # Ініціалізуємо вектор b нулями

    for i in range(n):
        # Заповнюємо матрицю за методом найменших квадратів
        for j in range(n):
            matrix[i, j] = np.sum(phi(x, i) * phi(x, j)) 
            print(matrix[i, j])

        b[i] = np.sum(y * phi(x, i))  # Заповнюємо вектор b

    return np.linalg.solve(matrix, b)[::-1]  # Розв'язуємо систему лінійних рівнянь і повертаємо коефіцієнти у зворотньому порядку

def MaxError(f_res, phi_res):
    return np.max(np.abs(f_res - phi_res))  # Обчислюємо максимальну похибку

def MeanError(f_res, phi_res):
    return np.mean(np.abs(f_res - phi_res))  # Обчислюємо середню похибку

def MeanSquaredError(f_res, phi_res):
    return np.sqrt(np.mean((f_res - phi_res) ** 2))  # Обчислюємо середньоквадратичну похибку

new_x = np.linspace(X[0], X[-1], 100)  # Масив нових значень x для візуалізації
coefficients = GetCoefficients(X, Y, 15)  # Отримуємо коефіцієнти апроксимуючого полінома

f = np.poly1d(coefficients)  # Створюємо поліном за допомогою коефіцієнтів

print('Максимальна похибка: ', MaxError(Y, f(X)))  # Виводимо максимальну похибку
print('Середня похибка', MeanError(Y, f(X)))  # Виводимо середню похибку
print('Середньоквадратична похибка', MeanSquaredError(Y, f(X)))  # Виводимо середньоквадратичну похибку

plt.figure(figsize=(8, 6))  # Створюємо нову фігуру для графіка

plt.plot(new_x, f(new_x), color='yellow', label='Середньоквадратичне наближення')  # Візуалізуємо апроксимаційний поліном
plt.plot(X, Y, '--bo', label='Початкова функція')  # Візуалізуємо початкові дані

plt.legend()  # Додаємо легенди
plt.show()  # Показуємо графік
