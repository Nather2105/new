import numpy as np  # Імпортуємо бібліотеку numpy для роботи з масивами та математичними операціями
import matplotlib.pyplot as plt  # Імпортуємо бібліотеку matplotlib.pyplot для побудови графіків
from typing import Callable  # Імпортуємо тип Callable з модуля typing для анотування функцій

func = Callable[[float], float]  # Оголошуємо псевдонім func для типу Callable[[float], float]

# функція для створення тридіагональної матриці
def tridiagonal_matrix(a, b, c):
    return np.diag(a, -1) + np.diag(b, 0) + np.diag(c, 1)
    # Створюємо тридіагональну матрицю, об'єднавши діагоналі a, b і c за допомогою функції np.diag

# основний клас для реалізації
class BoundaryValueProblem:
    def __init__(self, x0: float, x1: float, u0: float, u1: float, n: int, p: func, q: func, r: func):
        self.n = n  # Зберігаємо значення параметра n
        self.x0, self.x1 = x0, x1  # Зберігаємо значення параметрів x0 і x1
        self.u0, self.u1 = u0, u1  # Зберігаємо значення параметрів u0 і u1

        self.p, self.q, self.r = p, q, r  # Зберігаємо функції p, q і r

    # побудова матриці
    def get_matrix(self) -> tuple[np.ndarray, np.ndarray]:
        h = (self.x1 - self.x0) / self.n  # Обчислюємо крок h

        d_array = np.zeros(self.n - 1)  # Ініціалізуємо масив d_array нулями
        a_array, b_array, c_array = np.zeros(self.n - 1), np.zeros(self.n - 1), np.zeros(self.n - 1)
        # Ініціалізуємо масиви a_array, b_array, c_array нулями

        for i in range(self.n - 1):
            xi = self.x0 + (i + 1) * h  # Обчислюємо значення xi для поточного індексу i

            if i == 0:
                d_array[i] = h * h * self.r(xi) - (1 - 0.5 * h * self.p(xi)) * self.u0
                # Обчислюємо значення d_array[i] для першого елемента
            elif i == self.n - 2:
                d_array[i] = h * h * self.r(xi) - (1 + 0.5 * h * self.p(xi)) * self.u1
                # Обчислюємо значення d_array[i] для останнього елемента
            else:
                d_array[i] = h * h * self.r(xi)
                # Обчислюємо значення d_array[i] для інших елементів

            a_array[i] = 1 - 0.5 * h * self.p(xi)  # Обчислюємо значення a_array[i]
            b_array[i] = -2 + h * h * self.q(xi)  # Обчислюємо значення b_array[i]
            c_array[i] = 1 + 0.5 * h * self.p(xi)  # Обчислюємо значення c_array[i]

        return tridiagonal_matrix(a_array[1:], b_array, c_array[:-1]), d_array
        # Повертаємо тридіагональну матрицю та масив d_array

    # вирішення
    def solve(self) -> np.ndarray:
        y = np.linalg.solve(*self.get_matrix())  # Виконуємо розв'язок системи рівнянь
        return np.concatenate(([self.u0], y, [self.u1]))  # Повертаємо розв'язок з доданими початковими та кінцевими значеннями

    # побудова
    def plot(self) -> None:
        h = (self.x1 - self.x0) / self.n  # Обчислюємо крок h

        _, ax = plt.subplots()  # Створюємо об'єкт графіку
        ax.plot(np.arange(self.x0, self.x1 + h / 2, h), self.solve())  # Побудова графіку розв'язку

    # вивід коренів
    def print_roots(self) -> None:
        print('Корені:')
        for i, root in enumerate(self.solve()):
            print(f"y{i} = {root}")  # Виведення значень розв'язку

# функція для знаходження відхилення на сітках
def max_deviation(sol1: np.ndarray, sol2: np.ndarray) -> float:
    sol2 = np.array([el for i, el in enumerate(sol2) if i % 2 == 0])
    # Фільтруємо другий розв'язок, вибираючи лише елементи з парними індексами
    return np.max(np.abs(sol2 - sol1))  # Обчислюємо максимальне відхилення між розв'язками на сітках

# функція мейн для старту програми
if __name__ == '__main__':
    bvp = BoundaryValueProblem(x0=1, x1=2, u0=1.5, u1=4, n=10,
                            p=lambda x: 2,
                            q=lambda x: -4 / x,
                            r=lambda x: 2)
    # Створюємо об'єкт BoundaryValueProblem з заданими параметрами та функціями

    print('Матриця N = 10', bvp.get_matrix()[0], sep='\n')  # Виводимо матрицю з параметром N = 10
    s1 = bvp.solve()  # Розв'язуємо задачу
    bvp.print_roots()  # Виводимо значення розв'язку
    bvp.plot()  # Побудова графіку

    bvp.n = 20  # Змінюємо параметр n на 20
    print('Матриця N = 20:', bvp.get_matrix()[0], sep='\n')  # Виводимо матрицю з параметром N = 20
    s2 = bvp.solve()  # Розв'язуємо задачу з новим значенням n
    bvp.print_roots()  # Виводимо значення розв'язку
    print("Максимальне відхилення між розв'язками на сітках N=10 і N=20:")
    print(max_deviation(s1, s2))  # Виводимо максимальне відхилення між розв'язками

    plt.show()  # Показуємо графік
