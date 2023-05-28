import numpy as np
import matplotlib.pyplot as plt
from typing import Callable

func = Callable[[float], float]


# функція для створення тридіагональної матриці
def tridiagonal_matrix(a, b, c):
    return np.diag(a, -1) + np.diag(b, 0) + np.diag(c, 1)


# основний клас для реалізації
class BoundaryValueProblem:
    def __init__(self, x0: float, x1: float, u0: float, u1: float, n: int, p: func, q: func, r: func):
        self.n = n
        self.x0, self.x1 = x0, x1
        self.u0, self.u1 = u0, u1

        self.p, self.q, self.r = p, q, r

    # побудова матриці
    def get_matrix(self) -> tuple[np.ndarray, np.ndarray]:
        h = (self.x1 - self.x0) / self.n

        d_array = np.zeros(self.n - 1)
        a_array, b_array, c_array = np.zeros(self.n - 1), np.zeros(self.n - 1), np.zeros(self.n - 1)

        for i in range(self.n - 1):
            xi = self.x0 + (i + 1) * h

            if i == 0:
                d_array[i] = h * h * self.r(xi) - (1 - 0.5 * h * self.p(xi)) * self.u0
            elif i == self.n - 2:
                d_array[i] = h * h * self.r(xi) - (1 + 0.5 * h * self.p(xi)) * self.u1
            else:
                d_array[i] = h * h * self.r(xi)

            a_array[i] = 1 - 0.5 * h * self.p(xi)
            b_array[i] = -2 + h * h * self.q(xi)
            c_array[i] = 1 + 0.5 * h * self.p(xi)

        print(a_array, b_array, c_array)
        return tridiagonal_matrix(a_array[1:], b_array, c_array[:-1]), d_array

    # вирішення
    def solve(self) -> np.ndarray:
        y = np.linalg.solve(*self.get_matrix())
        return np.concatenate(([self.u0], y, [self.u1]))

    # побудова
    def plot(self) -> None:
        h = (self.x1 - self.x0) / self.n

        _, ax = plt.subplots()
        ax.plot(np.arange(self.x0, self.x1 + h / 2, h), self.solve())

    # вивід коренів
    def print_roots(self) -> None:
        print('Корені:')
        for i, root in enumerate(self.solve()):
            print(f"y{i} = {root}")


# функція для знаходження відхилення на сітках
def max_deviation(sol1: np.ndarray, sol2: np.ndarray) -> float:
    sol2 = np.array([el for i, el in enumerate(sol2) if i % 2 == 0])
    return np.max(np.abs(sol2 - sol1))

# функція мейн для старту програми
if __name__ == '__main__':
    # bvp = BoundaryValueProblem(x0=1, x1=2, u0=1.5, u1=4, n=10,
    #                         p=lambda x: 2,
    #                         q=lambda x: -4 / x,
    #                         r=lambda x: 2)
    bvp = BoundaryValueProblem(x0=1, x1=2, u0=4, u1=9, n=10,
                            p=lambda x: (2/(x+2)),
                            q=lambda x: -x,
                            r=lambda x: 6-x*((x+2)**(2)))


    print('Матриця N = 10', bvp.get_matrix()[0], sep='\n')
    s1 = bvp.solve()
    bvp.print_roots()
    bvp.plot()

    bvp.n = 20
    print('Матриця N = 20:', bvp.get_matrix()[0], sep='\n')
    s2 = bvp.solve()
    bvp.print_roots()

    print("Максимальне відхилення між розв'язками на сітках N=10 і N=20:")
    print(max_deviation(s1, s2))

    plt.show()
