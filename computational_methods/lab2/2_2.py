import random
import math

def norm(xk, xkp):
    norm = 0
    for i in range(len(xk)):
        norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i])
    return math.sqrt(norm)


def converge(xk, xkp, eps):
    return norm(xk, xkp) < eps


def jacobi_method(a, b, eps=0.0001):
    n = len(b)
    tmp_x = [0] * n
    x = list(b)
    p = [0] * n

    iter = 0

    while True:
        p = list(x)
        tmp_x = list(b)

        for i in range(n):
            for j in range(n):
                if i != j:
                    tmp_x[i] -= a[i][j] * p[j]

            x[i] = tmp_x[i] / a[i][i]

        iter += 1

        if converge(x, p, eps):
            break

    return x, iter


def output_solution(solution):
    x, iters = solution
    s = "Корені системи:\n"

    for i in range(len(x)):
        s += f"x{i + 1} = {x[i]}\n"

    s += f"Кількість ітерацій: {iters}\n"

    return s


def main():
    eps1 = 0.01
    eps2 = 0.0001
    matrix = [
        [3.141, -0.515, 0.321, -0.321],
        [0.341, 9.542, -1.647, 0.342],
        [0.311, -3.541, 14.241, 0.709],
        [1.444, -2.112, 0.413, 5.934]
    ]
    
    b = [3.104, 8.578, 12.031, 5.679]
    
    print("Метод Якобі з точністю " + str(eps1) + ":")
    solution = jacobi_method(matrix, b, eps1)
    print(output_solution(solution))
    print("Метод Якобі з точністю " + str(eps2) + ":")
    solution = jacobi_method(matrix, b, eps2)
    print(output_solution(solution))

if __name__ == "__main__":
    main()
