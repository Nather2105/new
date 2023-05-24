# Імпорт модулів
import matplotlib.pyplot as plt
import math

# Функція для обчислення тангенсу кута між двома точками
def compute_angle(p1, p2):
    dx = p2[0] - p1[0]
    dy = p2[1] - p1[1]
    return math.atan2(dy, dx)

# Функція для перевірки, чи утворюється правий поворот
def is_right_turn(p1, p2, p3):
        # зміщення по х між точками р2 та р1 * зміщення між точками р3 та р1 по у
        #  відняти
        # зміщення по у між точками р2 та р1 * зміщення між точками р3 та р1 по х 
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]) > 0
# Метод обходу Грехема
def graham_scan(points):
    # Знаходимо найнижчу точку (з найменшою y-координатою)
    lowest_point = min(points, key=lambda p: p[1])
    
    # Сортуємо точки за кутом відносно найнижчої точки
    sorted_points = sorted(points, key=lambda p: compute_angle(lowest_point, p))
    
    # Обхід точок
    # закидуємо в стек дві точки 
    stack = []
    stack.append(sorted_points[0])
    stack.append(sorted_points[1])
    
    # Цикл в якому ми проходимося по  всім відсортованим точкам і перевіряємо на умову "чи утворюється правий поворот"
    for i in range(2, len(sorted_points)):
        # і потім перевіряємо кожну наступну точну на утворення повороту направо 
        # якщо поворот здійснюється то закидуємо у стек, якщо ні то викидуємо останню точку із стеку та закидуємо наступну для перевірки
        while len(stack) >= 2 and not is_right_turn(stack[-2], stack[-1], sorted_points[i]):
            stack.pop()
        stack.append(sorted_points[i])
    
    return stack

# Тестові точки
points = [(0, 0), (1, 1), (1, 2), (2, 2), (2, 1), (1, 0), (3, 3), (-1, 3), (4, 5), (3, 1), (-1, 4), (1, 5)]

# Виклик методу обходу Грехема
convex_hull = graham_scan(points)

# Відображення точок та опуклої оболонки
x_coords = [point[0] for point in points]
y_coords = [point[1] for point in points]
plt.scatter(x_coords, y_coords, color='b', label='Точки')


hull_points = list(convex_hull) + [convex_hull[0]]  # Додаємо першу точку в кінець для замикання
# Відображення оболонки 
plt.plot([point[0] for point in hull_points], [point[1] for point in hull_points], color='r', label='Опукла оболонка')
# Встановлення лайбів та заголовку, вивід загального малюнку
plt.legend()
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Метод обходу Грехема')
plt.grid(True)
plt.show()