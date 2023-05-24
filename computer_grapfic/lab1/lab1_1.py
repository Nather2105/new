# підключення бібліотек
import pygame
from array import *
# закуск графічної бібліотеки
pygame.init()

# перевірка на випадок, якщо сторони лежать на одній прямій
def final_step(x1,y1,x2,y2,x3,y3,x4,y4):
    if x1 > x2:
        min_1 = [x2,y2]
        max_1 = [x1,y1]
    else:
        min_1 = [x1,y1]
        max_1 = [x2,y2]
    
    if x3 > x4:
        min_2 = [x4,y4]
        max_2 = [x3,y3]
    else:
        min_2 = [x3,y3]
        max_2 = [x4,y4]
    
    if min_1[0] == min_2[0]:
        start = min_2
        if max_1[0] >= max_2[0]:
            finish = max_2
        else:
            finish = max_1
        return [start[0], start[1], finish[0], finish[1]]        
    
    if max_1[0] == max_2[0]:
        start = max_2
        if min_1[0] > min_2[0]:
            finish = min_2
        else:
            finish = min_1
        return [start[0], start[1], finish[0], finish[1]]
    
    if min_1[0] < min_2[0] and max_1[0] > max_2[0]:
        start = min_2
        finish = max_2
        return [start[0], start[1], finish[0], finish[1]]
    
    if min_1[0] > min_2[0] and max_1[0] < max_2[0]:
        start = min_1
        finish = max_1
        return [start[0], start[1], finish[0], finish[1]]
    
    if min_1[0] < min_2[0]:
        if max_1[0] < min_2[0]:
            return 0
        elif max_1[0] > min_2[0]:
            start = min_2
            finish = max_1
            return [start[0], start[1], finish[0], finish[1]]
    
    if min_1[0] > min_2[0]:
        if max_2[0] < min_1[0]:
            return 0
        elif max_2[0] > min_1[0]:
            start = min_1
            finish = max_2
            return [start[0], start[1], finish[0], finish[1]]
    
    return 0

def find_the_answer(x1,y1, x2,y2, x3, y3, x4, y4):
    try:
        # створюємо з точок рівняння прямих
        mas1 = []
        mas1.append(y2-y1)
        mas1.append(-(x2-x1))
        mas1.append(-((y2-y1)*(-x1)-(x2-x1)*(-y1)))
        print(mas1)
        
        mas2 = []
        mas2.append(y4-y3)
        mas2.append(-(x4-x3))
        mas2.append(-((y4-y3)*(-x3)-(x4-x3)*(-y3)))
        print(mas2)
        
        # за методом гауса зводимо систему рівнянь до відповіді
        # (були неполадки з бібліотекою пайтону яка розв'язує системи власноруч тому виконав власноруч через метод Гауса)
        # тут зводимо на коефіцієнт біля х до 1 заради перевірки на паралельність
        if mas1[0] != 1 and mas1[0] != 0:
            changer = mas1[0]
            for i in range(0,3):
                mas1[i] =  mas1[i] / changer
        if mas2[0] != 1  and mas2[0] != 0:
            changer = mas2[0]
            for i in range(0,3):
                mas2[i] =  mas2[i] / changer
        if mas1[0] == 0 and mas1[1] != 0:
            changer = mas1[1]
            for i in range(1,3):
                mas1[i] =  mas1[i] / changer
        if mas2[0] == 0 and mas2[1] != 0:
            changer = mas2[1]
            for i in range(1,3):
                mas2[i] =  mas2[i] / changer
            
        # перевірка відповіді після зводження рівнянь
        # якщо рівняння однакові(пропорційні) то вони або пересікаються і мають декілька спільних точок або взагалі не пересікаються
        if(mas1 == mas2):
            if x1 == x2 and x2 == x3 and x3 == x4:
               answ = final_step(y1,x1,y2,x2,y3,x3,y4,x4)
               return [answ[1], answ[0], answ[3], answ[2]]
            else:
               return final_step(x1,y1,x2,y2,x3,y3,x4,y4)
                
        # прямі на яких лежать сторони трикутників є паралельними
        elif(mas1[0] == mas2[0] and mas1[1] == mas2[1] and mas1[2] != mas2[2]):
            return 1
        
        print(mas1)
        print(mas2)
        # заміна для кращого зводження методу Гауса
        if(mas2[1] == 0 or mas1[0] == 0):
            ans = [mas2, mas1]
        else:
            ans = [mas1, mas2]
            
        # сам метод Гауса 
        if(ans[1][0] != 0):
            changer = ans[1][0] / ans[0][0]
            for j in range(0,3):
                ans[1][j] = ans[1][j] - (ans[0][j] * changer)  
                
        print(ans)
        final = []
        y = ans[1][2] / ans[1][1]
        x = (ans[0][2] - (ans[0][1]* y)) / ans[0][0]
        final.append(x)
        final.append(y)
        print(final)
        
        # перевірка чи точка перетину точно входить в діапазон між двома прямими 
        if(final[0] >= min(x1,x2) and final[0] <= max(x1,x2) and final[0] >= min(x3,x4) and final[0] <= max(x3,x4) and
           final[1] >= min(y1,y2) and final[1] <= max(y1,y2) and final[1] >= min(y3,y4) and final[1] <= max(y3,y4)):
            return final
        
        return 1
        
    except ZeroDivisionError:
        return 1
    
    
# ініціалізація масивів для точок трикутників
arr_of_first_triangle = []
arr_of_second_triangle = []

first_point_of_first_triangle = []
second_point_of_first_triangle = []
third_point_of_first_triangle = []

first_point_of_second_triangle = []
second_point_of_second_triangle = []
third_point_of_second_triangle = []
# умова для відображення
print("x must be <= 15 and >= -15")
print("y must be <= 10 and >= -10")
print("only int available")
while 1:
    # прийняття точок з консолі та перевірка на умову для коректного відображення
    try:
        inp = input("input x for first point of first tringle:")
        if(int(inp) >= 15 or int(inp) <= -15):
            print("Error, x can not be >= 15 or <= -15 ")
            continue
        
        inp1 = input("input y for first point of first tringle:")
        if(int(inp1) >= 10 or int(inp1) <= -10):
            print("Error, y can not be >= 10 or <= -10 ")
            continue

        inp2 = input("input x for second point of first tringle:")
        if(int(inp2) >= 15 or int(inp2) <= -15):
            print("Error, x can not be >= 15 or <= -15 ")
            continue
        
        inp3 = input("input y for second point of first tringle:")
        if(int(inp3) >= 10 or int(inp3) <= -10):
            print("Error, y can not be >= 10 or <= -10 ")
            continue

        inp4 = input("input x for third point of first tringle:")
        if(int(inp4) >= 15 or int(inp4) <= -15):
            print("Error, x can not be >= 15 or <= -15")
            continue
        
        inp5 = input("input y for third point of first tringle:")
        if(int(inp5) >= 10 or int(inp5) <= -10):
            print("Error, y can not be >= 10 or <= -10 ")
            continue


        inp6 = input("input x for first point of second tringle:")
        if(int(inp6) >= 15 or int(inp6) <= -15):
            print("Error, x can not be >= 15 or <= -15")
            continue
        
        inp7 = input("input y for first point of second tringle:")
        if(int(inp7) >= 10 or int(inp7) <= -10):
            print("Error, y can not be >= 10 or <= -10 ")
            continue

        inp8 = input("input x for second point of second tringle:")
        if(int(inp8) >= 15 or int(inp8) <=  -15):
            print("Error, x can not be >= 15 or <= -15 ")
            continue
        
        inp9 = input("input y for second point of second tringle:")
        if(int(inp9) >= 10 or int(inp9) <= -10):
            print("Error, y can not be >= 10 or <= -10 ")
            continue

        inp10 = input("input x for third point of second tringle:")
        if(int(inp10) >= 15 or int(inp10) <= -15):
            print("Error, x can not be >= 15 or <= -15 ")
            continue
        
        inp11 = input("input y for third point of second tringle:")
        if(int(inp11) >= 10 or int(inp11) <= -10):
            print("Error, y can not be >= 10 or >= -10 ")
            continue
        # закидуємо точки в масиви 
        arr_of_first_triangle.append(int(inp))
        arr_of_first_triangle.append(int(inp1))
        arr_of_first_triangle.append(int(inp2))
        arr_of_first_triangle.append(int(inp3))
        arr_of_first_triangle.append(int(inp4))
        arr_of_first_triangle.append(int(inp5))
        
        arr_of_second_triangle.append(int(inp6))
        arr_of_second_triangle.append(int(inp7))
        arr_of_second_triangle.append(int(inp8))
        arr_of_second_triangle.append(int(inp9))
        arr_of_second_triangle.append(int(inp10))
        arr_of_second_triangle.append(int(inp11))
        
        # конвертуємо точки для їх відображення на графіці
        first_point_of_first_triangle.append(302 + 20 * int(inp))
        first_point_of_first_triangle.append(200 - 20 * int(inp1))
        second_point_of_first_triangle.append(302 + 20 * int(inp2))
        second_point_of_first_triangle.append(200 - 20 * int(inp3))
        third_point_of_first_triangle.append(302 + 20 * int(inp4))
        third_point_of_first_triangle.append(200 - 20 * int(inp5))
        
        first_point_of_second_triangle.append(302 + 20 * int(inp6))
        first_point_of_second_triangle.append(200 - 20 * int(inp7))
        second_point_of_second_triangle.append(302 + 20 * int(inp8))
        second_point_of_second_triangle.append(200 - 20 * int(inp9))
        third_point_of_second_triangle.append(302 + 20 * int(inp10))
        third_point_of_second_triangle.append(200 - 20 * int(inp11))
        break

    # ловимо помилки
    except ValueError:
        print("Error, float or not int input")
        arr_of_first_triangle = []
        arr_of_second_triangle = []
        first_point_of_first_triangle = []
        second_point_of_first_triangle = []
        third_point_of_first_triangle = []

        first_point_of_second_triangle = []
        second_point_of_second_triangle = []
        third_point_of_second_triangle = []
        continue

# ширина і висота вікна
W, H = 602, 402
# запуск вікна 
sc = pygame.display.set_mode((W, H))
pygame.display.set_caption("triangles")

# RGB відношення колорів
WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# відображаємо координатні вісі
pygame.draw.rect(sc, WHITE, (0,0, W, H))
pygame.draw.line(sc, BLACK, (300, 0), (300, 402), 3)
pygame.draw.line(sc, BLACK, (0, 200), (602, 200), 3)

# зоображаємо трикутники
pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
                            first_point_of_first_triangle[1]),
                            (second_point_of_first_triangle[0],
                            second_point_of_first_triangle[1]), 3)

pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
                            first_point_of_first_triangle[1]),
                            (third_point_of_first_triangle[0],
                            third_point_of_first_triangle[1]), 3)

pygame.draw.line(sc, BLACK, (third_point_of_first_triangle[0],
                            third_point_of_first_triangle[1]),
                            (second_point_of_first_triangle[0],
                            second_point_of_first_triangle[1]), 3)

pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
                            first_point_of_second_triangle[1]),
                            (second_point_of_second_triangle[0],
                            second_point_of_second_triangle[1]), 3)

pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
                            first_point_of_second_triangle[1]),
                            (third_point_of_second_triangle[0],
                            third_point_of_second_triangle[1]), 3)

pygame.draw.line(sc, BLACK, (third_point_of_second_triangle[0],
                            third_point_of_second_triangle[1]),
                            (second_point_of_second_triangle[0],
                            second_point_of_second_triangle[1]), 3)

# масив який допомагає на стадії порівняння сторін одна з одною
cycles =  [ 0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 2, 3,
            0, 1, 4, 5,
            0, 1, 2, 3,
            2, 3, 4, 5,
            0, 1, 4, 5, 
            0, 1, 2, 3,
            0, 1, 4, 5, 
            0, 1, 4, 5,
            0, 1, 4, 5, 
            2, 3, 4, 5,
            2, 3, 4, 5,
            0, 1, 2, 3,
            2, 3, 4, 5,
            0, 1, 4, 5,
            2, 3, 4, 5,
            2, 3, 4, 5]
# цикл в якому ми перевіряємо кожну сторону одного трикутника з кожною стороною другого трикутника на спільні точки
i = 0
for j in range(0,9):
    a = find_the_answer(arr_of_first_triangle[cycles[i]],
                    arr_of_first_triangle[cycles[i+1]],
                    arr_of_first_triangle[cycles[i+2]],
                    arr_of_first_triangle[cycles[i+3]],
                    arr_of_second_triangle[cycles[i+4]],
                    arr_of_second_triangle[cycles[i+5]],
                    arr_of_second_triangle[cycles[i+6]],
                    arr_of_second_triangle[cycles[i+7]])
    
    i += 8
    # якщо а = 0 то сторони не пересікаються, хоча і лежать на одній прямій
    if(a == 0):
        continue
    # якщо а = 1 то прямі на яких лежать сторони є паралельними
    if(a == 1):
        continue
    # конвертування для зображення на малюнку 
    first = 302 + 20 * a[0]
    second = 200 - 20 * a[1]
    
    # якщо повертається масив із 2 точками значить сторони перетинаються тільки в одній точці
    if len(a) == 2:
        pygame.draw.line(sc, RED, (first, second), (first + 2, second), 3)
    # якщо повертається масив із 4 точками значить сторони мають спільну ділянку яка складається із декількох точок
    elif len(a) == 4:
        third = 302 + 20 * a[2]
        fourth = 200 - 20 * a[3]
        pygame.draw.line(sc, RED, (first, second), (third, fourth), 3)


# вивід
pygame.display.update()

flRunning = True
while flRunning:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            flRunning = False
            
print("App still working")
            