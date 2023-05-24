# Підключаємо бібліотеки
import numpy as np
import matplotlib.pyplot as plt

# обчислення рекурентної формули умови завдання для змінної z разом із перевіркою чи вийшла точка за межі фракталу
def mandelbrot(a, b, max_iter):
    # оголошення z та c
    z = complex(0, 0)
    c = complex(a, b)
    # сам цикл для рекурентного знаходження z 
    for i in range(max_iter):
        z = z * z + c
        # перевірка на вихід за межі фракталу
        if abs(z) > 2:
            return i
        
    # повертає max_iter якщо точка не вийшла за межі
    return max_iter


def create_mandelbrot(width, height, a_range, b_range, max_iter):
    # рівномірно розділяємо значення між цими двома числами(-2.5, 2.5) та шириною
    a_vals = np.linspace(a_range[0], a_range[1], width)
    # рівномірно розділяємо значення між цими двома числами(-2, 2) та висотою
    b_vals = np.linspace(b_range[0], b_range[1], height)
    # створюємо пусту матрицю розмірністю висота на довжину
    image = np.empty((height, width))

    # кожну точку заповнюємо значеннями через функцію із рекурентною формулою
    for i in range(height):
        for j in range(width):
            a = a_vals[j]
            b = b_vals[i]
            image[i, j] = mandelbrot(a, b, max_iter)

    return image

# Параметри фрактала
width = 800
height = 400
a_range = (-2.5, 2.5)
b_range = (-2, 2)
max_iter = 100

# Генеруємо фрактала Мандельброта
fractal_image = create_mandelbrot(width, height, a_range, b_range, max_iter)

# Відображаємо фрактал
plt.imshow(fractal_image, cmap='hot', extent=[a_range[0], a_range[1], b_range[0], b_range[1]])
# встановлюємо назву зображення
plt.title("Фрактал Мандельброта")
# встановлюємо лайбли 
plt.xlabel("Re(c)")
plt.ylabel("Im(c)")
# відтворюємо
plt.show()