import pygame
from array import *
pygame.init()

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
        first_point_of_first_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for first point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        first_point_of_first_triangle.append(202 - 10 * int(inp))

        inp = input("input x for second point of first tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        second_point_of_first_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for second point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        second_point_of_first_triangle.append(202 - 10 * int(inp))

        inp = input("input x for third point of first tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        third_point_of_first_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for third point of first tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        third_point_of_first_triangle.append(202 - 10 * int(inp))


        inp = input("input x for first point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        first_point_of_second_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for first point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        first_point_of_second_triangle.append(202 - 10 * int(inp))

        inp = input("input x for second point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        second_point_of_second_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for second point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        second_point_of_second_triangle.append(202 - 10 * int(inp))

        inp = input("input x for third point of second tringle:")
        if(int(inp) > 30):
            print("Error, x can not be > 30 ")
            continue
        third_point_of_second_triangle.append(302 + 10 * int(inp))
        
        inp = input("input y for third point of second tringle:")
        if(int(inp) > 20):
            print("Error, y can not be > 20 ")
            continue
        third_point_of_second_triangle.append(202 - 10 * int(inp))
        
        break

    except ValueError:
        print("Error, float or not int input")
        continue

W, H = 602, 402
sc = pygame.display.set_mode((W, H))
pygame.display.set_caption("triangles")

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
# pygame.gfxdraw.pixel(sc, (first_point_of_first_triangle[0], first_point_of_first_triangle[1]), BLACK)

# first triangle
# pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
#                             first_point_of_first_triangle[1]),
#                             (second_point_of_first_triangle[0],
#                             second_point_of_first_triangle[1]), 2)

# pygame.draw.line(sc, BLACK, (first_point_of_first_triangle[0],
#                             first_point_of_first_triangle[1]),
#                             (third_point_of_first_triangle[0],
#                             third_point_of_first_triangle[1]), 2)

# pygame.draw.line(sc, BLACK, (third_point_of_first_triangle[0],
#                             third_point_of_first_triangle[1]),
#                             (second_point_of_first_triangle[0],
#                             second_point_of_first_triangle[1]), 2)

# pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
#                             first_point_of_second_triangle[1]),
#                             (second_point_of_second_triangle[0],
#                             second_point_of_second_triangle[1]), 2)

# pygame.draw.line(sc, BLACK, (first_point_of_second_triangle[0],
#                             first_point_of_second_triangle[1]),
#                             (third_point_of_second_triangle[0],
#                             third_point_of_second_triangle[1]), 2)

# pygame.draw.line(sc, BLACK, (third_point_of_second_triangle[0],
#                             third_point_of_second_triangle[1]),
#                             (second_point_of_second_triangle[0],
#                             second_point_of_second_triangle[1]), 2)

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
            