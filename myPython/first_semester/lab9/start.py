from module1 import* 

t = tpoint(1, 2)
pprint(t)
line1 = line(1, 2, 3, 4)
line_print(line1)
print(length_of_line(line1))
print(line_include_point_qm(line1, 1, 2))
print(point_in_line(line1, 1, 2))
print(area_of_triangle(line1,-1,3))


array1 = open_file_with_points('points.txt')
array2 = open_file_with_lines('lines.txt')
line_print(counter(array1, array2))