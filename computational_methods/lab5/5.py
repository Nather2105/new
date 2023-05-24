# # import math

# # def c(t):
# #     return 5 + (0.5 * t * math.sin(t**2))
# # def integral_simpson(a, b, n):
# #     h = (b - a) / n  # Ширина кожного підінтервалу
# #     x = a  # Початкове значення x
# #     integral = c(a) + c(b)  # Додаємо значення на краях відрізка

# #     # Обчислюємо значення на парних підінтервалах
# #     for i in range(1, n, 2):
# #         x += h
# #         integral += 4 * c(x)

# #     x = a + h  # Початкове значення x для непарних підінтервалів

# #     # Обчислюємо значення на непарних підінтервалах
# #     for i in range(2, n, 2):
# #         x += h
# #         integral += 2 * c(x)

# #     return integral * h / 3  # Повертаємо апроксимацію інтегралу

# # a = 0
# # b = 2
# # n = 100  # Прикладове значення кількості підінтервалів

# # result = integral_simpson(a, b, n)
# # print("Кількість теплоти:", result)

# import math

# def c(t):
#     return 5 + (0.5 * t * math.sin(t**2))

# def integral_simpson(a, b, n):
#     h = (b - a) / n  # Ширина кожного підінтервалу
#     x = a  # Початкове значення x
#     integral = c(a) + c(b)  # Додаємо значення на краях відрізка

#     # Обчислюємо значення на парних підінтервалах
#     for i in range(1, n):
#         x += h
#         if i % 2 == 0:
#             integral += 2 * c(x)
#         else:
#             integral += 4 * c(x)

#     return integral * h / 3  # Повертаємо апроксимацію інтегралу

# a = 0
# b = 2
# n = 100  # Прикладове значення кількості підінтервалів

# result = integral_simpson(a, b, n)
# print("Кількість теплоти:", result)


import math

def c(t):
    return 5 + 0.5 * t * math.sin(t**2)

def composite_simpson(a, b, h):
    n = int((b - a) / h)
    integral = c(a) + c(b)

    for i in range(1, n):
        x = a + i * h
        if i % 2 == 0:
            integral += 2 * c(x)
        else:
            integral += 4 * c(x)

    return integral * h / 3

a = 0
b = 2

h1 = 0.01  # Перший крок
result1 = composite_simpson(a, b, h1)
print(f"Кількість теплоти з кроком {h1}: {result1}")

h2 = 0.001  # Другий крок
result2 = composite_simpson(a, b, h2)
print(f"Кількість теплоти з кроком {h2}: {result2}")
