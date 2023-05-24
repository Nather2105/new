import numpy as np

def jacobi_method(matrix, b, epsilon1, epsilon2):
    n = len(matrix)
    x = np.zeros(n)
    x_new = np.zeros(n)
    iterations1 = 0
    iterations2 = 0
    
    # Перетворення системи рівнянь для забезпечення достатньої умови збіжності
    diagonal = matrix.diagonal()
    matrix_normalized = matrix / diagonal[:, np.newaxis]
    b_normalized = b / diagonal
    
    while True:
        x_new = np.zeros(n)
        
        for i in range(n):
            x_new[i] = b_normalized[i] - np.dot(matrix_normalized[i, :i], x[:i]) - np.dot(matrix_normalized[i, i+1:], x[i+1:])
        
        # Обчислення похибки
        error = np.linalg.norm(x_new - x, ord=np.inf)
        
        print("Iteration (ε1):", iterations1+1)
        print("x_new (ε1):", x_new)
        print("Error (ε1):", error)
        
        if np.isnan(x_new).any() or error <= epsilon1:
            break
        
        x = x_new.copy()
        iterations1 += 1
    
    x = np.zeros(n)
    
    while True:
        x_new = np.zeros(n)
        
        for i in range(n):
            x_new[i] = b_normalized[i] - np.dot(matrix_normalized[i, :i], x[:i]) - np.dot(matrix_normalized[i, i+1:], x[i+1:])
        
        # Обчислення похибки
        error = np.linalg.norm(x_new - x, ord=np.inf)
        
        print("Iteration (ε2):", iterations2+1)
        print("x_new (ε2):", x_new)
        print("Error (ε2):", error)
        
        if np.isnan(x_new).any() or error <= epsilon2:
            break
        
        x = x_new.copy()
        iterations2 += 1
    
    return x_new, iterations1, iterations2

matrix = np.array([[3.141, -0.515, 0.321, -0.321],
                   [1.444, -2.112, 0.413, 5.934],
                   [0.311, -3.541, 14.241, 0.709],
                   [0.341, 9.542, -1.647, 0.342]])

b = np.array([3.104, 5.679, 12.031, 8.578])

epsilon1 = 0.01
epsilon2 = 0.0001

solution, iterations1, iterations2 = jacobi_method(matrix, b, epsilon1, epsilon2)

print("Approximate solution:", solution)
print("Number of iterations for ε1 =", epsilon1, ":", iterations1)
print("Number of iterations for ε2 =", epsilon2, ":", iterations2)
