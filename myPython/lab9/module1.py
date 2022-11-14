from math import sqrt
from os import path
def tpoint(x, y):
    return [x,y]


def pprint(point):
    print(f"t({point[0]}, {point[1]})")


def line(x1, y1, x2, y2):
    a = tpoint(x1, y1)
    b = tpoint(x2, y2)
    return [a,b]

def line_print(line):
    if(line == 0):
        exit('error')
    print(f"Відрізок: A({str(line[0][0])}, {str(line[0][1])}), B({str(line[1][0])}, {str(line[1][1])})")
def length_of_line(line):
    return sqrt((line[1][0] - line[0][0])**2 + (line[1][1] - line[0][1])**2)

def line_include_point_qm(line,x, y):
    if (1 / 2) * ((int(line[0][0]) - x) * (int(line[1][1]) - y) - (int(line[1][0]) - x) * (int(line[0][1]) - y)) == 0:
        return True
    else:
        return False
def point_in_line(line, x, y):
    test = (x-line[0][0])*(line[1][1]-line[0][1])-(y-line[0][1])*(line[1][0]-line[0][0])
    if test == 0 and (line[0][0] < x < line[1][0] or line[1][0] < x < line[0][0]):
        return True
    else:
        return False
def area_of_triangle(line, x, y):
    first = (line[0][0] * line[1][1] + line[1][0]*y + x*line[0][1])
    second = (line[0][1] * line[1][0] + line[1][1]*x + y*line[0][0])
    return (1/2)*(first - second)
    
def open_file_with_points(name):
    array_with_points = []
    if path.exists(name):
        with open(name, "r", encoding="utf-8") as file:
            if path.getsize(name):
                for i in file:
                    x, y = i.split()
                    array_with_points.append(tpoint(x, y))
            else:
                print("error")
                exit()
    else:
        print("error")
        exit()
    return array_with_points
    
def open_file_with_lines(name):
    array_with_lines = []
    if path.exists(name):
        with open(name, "r", encoding="utf-8") as file:
            if path.getsize(name):
                for i in file:
                    x, y, z, q = i.split()
                    array_with_lines.append(line(x, y, z, q))
            else:
                print("error")
                exit()
    else:
        print("error")
        exit()
    return array_with_lines
    
def counter(array_with_points, array_with_lines):
    counter_for_lines = []
    max1 = []
    count_max = 0
    for i in array_with_lines:
        count = 0
        for j in array_with_points:
            if line_include_point_qm(i, int(j[0]), int(j[1])):
                count+=1
        if count > count_max:
            count_max = count
            max1 = i
    if count_max == 0:
            max1 = 0
    
    return max1





