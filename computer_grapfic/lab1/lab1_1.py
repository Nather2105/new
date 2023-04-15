# import numpy
import pygame
from array import *
pygame.init()


def find_the_answer(x1,y1, x2,y2, x3, y3, x4, y4):
    try:
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
        
        if mas1[0] != 1 and mas1[0] != 0:
            changer = mas1[0]
            # print(changer)
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
            
        if(mas1 == mas2):
            print("found many solutions in system of equations, so we can`t show it to you")
            if x1 == x2 and x2 == x3 and x3 == x4:
                print("awer")
            else:
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
                
                    
                    
                        
            
            # return 0
        elif(mas1[0] == mas2[0] and mas1[1] == mas2[1] and mas1[2] != mas2[2]):
            return 1
        print(mas1)
        print(mas2)
        if(mas2[1] == 0 or mas1[0] == 0):
            ans = [mas2, mas1]
        else:
            ans = [mas1, mas2]
            
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
        
        # print(max(x1,x2,x3,x4))
        # print(min(x1,x2,x3,x4))
        # print(max(y1,y2,y3,y4))
        # print(min(y1,y2,y3,y4))
        if(final[0] >= min(x1,x2) and final[0] <= max(x1,x2) and final[0] >= min(x3,x4) and final[0] <= max(x3,x4) and
           final[1] >= min(y1,y2) and final[1] <= max(y1,y2) and final[1] >= min(y3,y4) and final[1] <= max(y3,y4)):
            return final
        
        return 1
        
        # if final[1] > max(y1,y2,y3,y4) or final[1] < min(y1,y2,y3,y4):
        #     return 1
        
        
        
    except ZeroDivisionError:
        return 1
    
    

arr_of_first_triangle = []
arr_of_second_triangle = []
first_point_of_first_triangle = []
second_point_of_first_triangle = []
third_point_of_first_triangle = []

first_point_of_second_triangle = []
second_point_of_second_triangle = []
third_point_of_second_triangle = []
print("x must be <= 20 and >= -20")
print("y must be <= 10 and >= -10")
print("only int available")
while 1:
    try:
        inp = input("input x for first point of first tringle:")
        if(int(inp) > 20 or int(inp) < -20):
            print("Error, x can not be > 20 or < -20 ")
            continue
        
        
        inp1 = input("input y for first point of first tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or < -10 ")
            continue

        inp2 = input("input x for second point of first tringle:")
        if(int(inp) > 20 or int(inp) < -20):
            print("Error, x can not be > 20 or < -20 ")
            continue
        
        inp3 = input("input y for second point of first tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or < -10 ")
            continue

        inp4 = input("input x for third point of first tringle:")
        if(int(inp) > 20 or int(inp) < -20):
            print("Error, x can not be > 20 or < -20")
            continue
        
        inp5 = input("input y for third point of first tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or < -10 ")
            continue


        inp6 = input("input x for first point of second tringle:")
        if(int(inp) > 20 or int(inp) < -20):
            print("Error, x can not be > 20 or < -20")
            continue
        
        inp7 = input("input y for first point of second tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or < -10 ")
            continue

        inp8 = input("input x for second point of second tringle:")
        if(int(inp) > 20 or int(inp) <  -20):
            print("Error, x can not be > 20 or < -20 ")
            continue
        
        inp9 = input("input y for second point of second tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or < -10 ")
            continue

        inp10 = input("input x for third point of second tringle:")
        if(int(inp) > 20 or int(inp) < -20):
            print("Error, x can not be > 20 or < -20 ")
            continue
        
        inp11 = input("input y for third point of second tringle:")
        if(int(inp) > 10 or int(inp) < -10):
            print("Error, y can not be > 10 or > -10 ")
            continue
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
        print(arr_of_first_triangle)
        print()
        print(arr_of_second_triangle)
        
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

W, H = 602, 402
sc = pygame.display.set_mode((W, H))
pygame.display.set_caption("triangles")


# exit()

# print(first_point_of_first_triangle[0])
# print(first_point_of_first_triangle[1])
# print(second_point_of_first_triangle[0])
# print(second_point_of_first_triangle[1])
# exit()
WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
# menu
pygame.draw.rect(sc, WHITE, (0,0, W, H))
pygame.draw.line(sc, BLACK, (300, 0), (300, 402), 3)
pygame.draw.line(sc, BLACK, (0, 200), (602, 200), 3)
# pygame.gfxdraw.pixel(sc, (first_point_of_first_triangle[0], first_point_of_first_triangle[1]), WHITE)

# first triangle
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
    # print(a)
    i += 8
    if(a == 0):
        # print("sorry, try again")
        continue
    if(a == 1):
        # print("sorry, try again")
        continue
    first = 302 + 20 * a[0]
    second = 200 - 20 * a[1]
    
    # sc.set_at((first, second), RED)
    if len(a) == 2:
        pygame.draw.line(sc, RED, (first, second), (first + 2, second), 3)
    elif len(a) == 4:
        third = 302 + 20 * a[2]
        fourth = 200 - 20 * a[3]
        pygame.draw.line(sc, RED, (first, second), (third, fourth), 3)

pygame.display.update()

flRunning = True

while flRunning:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            # exit()
            # pass
            pygame.quit()
            flRunning = False
            
print("App still working")
            