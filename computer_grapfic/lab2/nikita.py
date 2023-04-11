# import pygame
# import sys

# # Инициализация Pygame
# pygame.init()

# # Размер экрана
# screen_size = (1000, 1000)

# # Создание экрана
# screen = pygame.display.set_mode(screen_size)

# # Цвета
# white = (255, 255, 255)
# black = (0, 0, 0)

# # Размер и координаты начального квадрата
# square_size = 1000
# square_x = 0
# square_y = 0


# # Рекурсивная функция для рисования Квадрата Серпинского
# def draw_square(x, y, size):
#     # Остановка рекурсии при размере квадрата менее 5 пикселей
#     if size < 5:
#         return
#     # Рисование внешнего квадрата
#     pygame.draw.rect(screen, black, (x, y, size, size), 1)
#     # Рисование центрального квадрата
#     pygame.draw.rect(screen, white, (x + size/3, y + size/3, size/3, size/3))
#     # Вызов функции для каждого из 8 новых квадратов
#     new_size = size/3
#     draw_square(x, y, new_size)
#     draw_square(x + new_size, y, new_size)
#     draw_square(x + 2*new_size, y, new_size)
#     draw_square(x, y + new_size, new_size)
#     draw_square(x + 2*new_size, y + new_size, new_size)
#     draw_square(x, y + 2*new_size, new_size)
#     draw_square(x + new_size, y + 2*new_size, new_size)
#     draw_square(x + 2*new_size, y + 2*new_size, new_size)


# # Запуск рисования Квадрата Серпинского
# draw_square(square_x, square_y, square_size)

# # Обновление экрана
# pygame.display.flip()

# # Основной цикл программы
# while True:
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             pygame.quit()
#             sys.exit()
import turtle
import math
import time
import numpy

def draw_triangle(x1, y1, x2, y2, x3, y3):
    turtle.penup()
    turtle.goto(x1, y1)
    turtle.pendown()
    turtle.goto(x2, y2)
    turtle.goto(x3, y3)
    turtle.goto(x1, y1)

def draw_incircle(x1, y1, x2, y2, x3, y3):
    a = math.sqrt((x2 - x3)**2 + (y2 - y3)**2)
    b = math.sqrt((x1 - x3)**2 + (y1 - y3)**2)
    c = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
    s = (a + b + c) / 2
    r = math.sqrt((s * (s - a) * (s - b) * (s - c))) / s
    x = (a * x1 + b * x2 + c * x3) / (a + b + c)
    y = (a * y1 + b * y2 + c * y3) / (a + b + c)
    turtle.penup()
    turtle.goto(x, y - r)
    turtle.pendown()
    turtle.circle(r)

x1, y1 = 0, 0
x2, y2 = 20, 50
x3, y3 = 80, 0

turtle.speed(0)
for i in range(100):
    turtle.clear()
    x2 += 1
    y2 += 1
    draw_triangle(x1, y1, x2, y2, x3, y3)
    draw_incircle(x1, y1, x2, y2, x3, y3)
    time.sleep(0.05)
turtle.done()