import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import time
# Оголошення координат вершин платонових тіл
icosahedron_vertices = np.array([
    [-0.525731, 0, 0.850651],
    [0.525731, 0, 0.850651],
    [-0.525731, 0, -0.850651],
    [0.525731, 0, -0.850651],
    [0, 0.850651, 0.525731],
    [0, 0.850651, -0.525731],
    [0, -0.850651, 0.525731],
    [0, -0.850651, -0.525731],
    [0.850651, 0.525731, 0],
    [0.850651, -0.525731, 0],
    [-0.850651, 0.525731, 0],
    [-0.850651, -0.525731, 0]
])

dodecahedron_vertices = np.array([
    [0.356822, 0.356822, 0.356822],
    [-0.356822, 0.356822, 0.356822],
    [-0.356822, -0.356822, 0.356822],
    [0.356822, -0.356822, 0.356822],
    [0.356822, 0.356822, -0.356822],
    [-0.356822, 0.356822, -0.356822],
    [-0.356822, -0.356822, -0.356822],
    [0.356822, -0.356822, -0.356822],
    [0, 0.470228, 0.652663],
    [0, -0.470228, 0.652663],
    [0, 0.470228, -0.652663],
    [0, -0.470228, -0.652663],
    [0.470228, 0.652663, 0],
    [-0.470228, 0.652663, 0],
    [0.470228, -0.652663, 0],
    [-0.470228, -0.652663, 0],
    [0.652663, 0, 0.470228],
    [0.652663, 0, -0.470228],
    [-0.652663, 0, 0.470228],
    [-0.652663, 0, -0.470228]
])

# Оголошення осі обертання
# Оборот йде навколо початку простору
axis = np.array([1, 0, 0])

# Оголошення функції для обертання тіла навколо осі
def rotate_body(vertices, axis, angle):
    # Створення матриці обертання
    theta = np.radians(angle) # Переведення кута в радіанти
    c = np.cos(theta) #  Обчислення косинуса кута
    s = np.sin(theta) # обчислення синуса кута
    
    # Створення матриці обертання з використанням формул Радріга
    rotation_matrix = np.array([
    [c + axis[0] ** 2 * (1 - c), axis[0] * axis[1] * (1 - c) - axis[2] * s, axis[0] * axis[2] * (1 - c) + axis[1] * s],
    [axis[1] * axis[0] * (1 - c) + axis[2] * s, c + axis[1] ** 2 * (1 - c), axis[1] * axis[2] * (1 - c) - axis[0] * s],
    [axis[2] * axis[0] * (1 - c) - axis[1] * s, axis[2] * axis[1] * (1 - c) + axis[0] * s, c + axis[2] ** 2 * (1 - c)]
    ])


    
    # Обертання вершин тіла шляхом множення на матрицю оберання
    rotated_vertices = np.dot(vertices, rotation_matrix.T)
    
    return rotated_vertices

# Оголошення функції для відображення тіл
def visualize_bodies(vertices1, vertices2):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    # Відображення вершин першого тіла
    ax.scatter(vertices1[:, 0], vertices1[:, 1], vertices1[:, 2], c='blue')
    # ax.plot_trisurf(vertices1[:, 0], vertices1[:, 1], vertices1[:, 2], linewidth=0.2)    
    # Відображення вершин другого тіла
    ax.scatter(vertices2[:, 0], vertices2[:, 1], vertices2[:, 2], c='red')
    # ax.plot_trisurf(vertices2[:, 0], vertices2[:, 1], vertices2[:, 2], linewidth=0.2, antialiased=True)


    # Візуалізація платонових тіл
    # Налаштування відображення
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_xlim(-1, 1)
    ax.set_ylim(-1, 1)
    ax.set_zlim(-1, 1)
    
    # Відображення графіка
    plt.show()
    

# Обертання тіл навколо осі та візуалізація
# Цикл який проходить через значення кутів обертання з кроком 10 градусів
for angle in range(0, 360, 10):
    # повертаємо  ікосаедр
    rotated_icosahedron = rotate_body(icosahedron_vertices, axis, angle)
    # повертаємо додекаедр
    rotated_dodecahedron = rotate_body(dodecahedron_vertices, axis, angle) 
    
    visualize_bodies(rotated_icosahedron, rotated_dodecahedron)

