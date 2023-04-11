import numpy
import pygame
from array import *
pygame.init()


def find_the_answer(x1,y1, x2,y2, x3, y3, x4, y4):
    mas1 = []
    mas1.append(y2-y1)
    mas1.append(-(x2-x1))
    mas1.append((y2-y1)*(-x1)-(x2-x1)*(-y1))
    print(mas1)
    
    mas2 = []
    mas2.append(y4-y3)
    mas2.append(-(x4-x3))
    mas2.append((y4-y3)*(-x3)-(x4-x3)*(-y3))
    print(mas2)
    
    if mas1[0] != 1:
        for i in range(0,3):
            mas1[i] =  mas1[i] / mas1[0]
    if mas2[0] != 1:
        for i in range(0,3):
            mas2[i] =  mas2[i] / mas2[0]
    if(mas1 == mas2):
        # todo func for many points
        print("yes, they are equal")
    print(mas1)
    print(mas2)
    ans = [mas1, mas2]
    print(ans)
    

arr_of_first_triangle = []
arr_of_second_triangle = []
first_point_of_first_triangle = []
second_point_of_first_triangle = []
third_point_of_first_triangle = []

first_point_of_second_triangle = []
second_point_of_second_triangle = []
third_point_of_second_triangle = []
print("x must be <= 30")
print("y must be <= 20")
print("only int available")
while 1:
    try:
        inp = input("input x for first point of first tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        
        inp1 = input("input y for first point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue

        inp2 = input("input x for second point of first tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        inp3 = input("input y for second point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue

        inp4 = input("input x for third point of first tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        inp5 = input("input y for third point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue


        inp6 = input("input x for first point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        inp7 = input("input y for first point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue

        inp8 = input("input x for second point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        inp9 = input("input y for second point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue

        inp10 = input("input x for third point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        
        inp11 = input("input y for third point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
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
        
        first_point_of_first_triangle.append(302 + 10 * int(inp))
        first_point_of_first_triangle.append(200 - 10 * int(inp1))
        second_point_of_first_triangle.append(302 + 10 * int(inp2))
        second_point_of_first_triangle.append(200 - 10 * int(inp3))
        third_point_of_first_triangle.append(302 + 10 * int(inp4))
        third_point_of_first_triangle.append(200 - 10 * int(inp5))
        
        first_point_of_second_triangle.append(302 + 10 * int(inp6))
        first_point_of_second_triangle.append(200 - 10 * int(inp7))
        second_point_of_second_triangle.append(302 + 10 * int(inp8))
        second_point_of_second_triangle.append(200 - 10 * int(inp9))
        third_point_of_second_triangle.append(302 + 10 * int(inp10))
        third_point_of_second_triangle.append(200 - 10 * int(inp11))
        break

    except ValueError:
        print("Error, float or not int input")
        continue

W, H = 602, 402
sc = pygame.display.set_mode((W, H))
pygame.display.set_caption("triangles")

find_the_answer(arr_of_first_triangle[0],
                arr_of_first_triangle[1],
                arr_of_first_triangle[2],
                arr_of_first_triangle[3],
                arr_of_first_triangle[4],
                arr_of_first_triangle[5],
                arr_of_second_triangle[0],
                arr_of_second_triangle[1])

exit()

print(first_point_of_first_triangle[0])
print(first_point_of_first_triangle[1])
print(second_point_of_first_triangle[0])
print(second_point_of_first_triangle[1])
# exit()
WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
sc.set_at((first_point_of_first_triangle[0], first_point_of_first_triangle[1]), RED)
# menu
pygame.draw.rect(sc, WHITE, (0,0, W, H))
pygame.draw.line(sc, BLACK, (300, 0), (300, 402), 3)
pygame.draw.line(sc, BLACK, (0, 200), (602, 200), 3)
# pygame.gfxdraw.pixel(sc, (first_point_of_first_triangle[0], first_point_of_first_triangle[1]), GREEN)

# first triangle
pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
                            first_point_of_first_triangle[1]),
                            (second_point_of_first_triangle[0],
                            second_point_of_first_triangle[1]), 2)

pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
                            first_point_of_first_triangle[1]),
                            (third_point_of_first_triangle[0],
                            third_point_of_first_triangle[1]), 2)

pygame.draw.line(sc, BLACK, (third_point_of_first_triangle[0],
                            third_point_of_first_triangle[1]),
                            (second_point_of_first_triangle[0],
                            second_point_of_first_triangle[1]), 2)

pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
                            first_point_of_second_triangle[1]),
                            (second_point_of_second_triangle[0],
                            second_point_of_second_triangle[1]), 2)

pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
                            first_point_of_second_triangle[1]),
                            (third_point_of_second_triangle[0],
                            third_point_of_second_triangle[1]), 2)

pygame.draw.line(sc, BLACK, (third_point_of_second_triangle[0],
                            third_point_of_second_triangle[1]),
                            (second_point_of_second_triangle[0],
                            second_point_of_second_triangle[1]), 2)

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
            