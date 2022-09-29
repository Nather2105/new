from random import randint

n = input()
m = input()
matr = [[] for i in range(n)] 
vekt = []

for i in range(n):
    for j in range(n):
      matr[i].append(randint(-30,30))

for i in range(m):
    vekt.append(randint(-30,30))


print(matr)
print(vekt)

for i in range(n):
    for j in range(n):
        if matr[i][j] not in vekt:
            matr[i][j] = 0


print(matr)

