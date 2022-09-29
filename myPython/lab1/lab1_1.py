import math
a = 4
b = 300.1
c = 7.2 * (a+b) ** ((1 + math.cos(a) ** 2) * (1 - math.cos(b)) + 0.711 * math.log(a+b))
print("answer is " + str(c))