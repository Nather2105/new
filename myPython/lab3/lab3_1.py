from random import randint

a = []
count = 0
n = input("input n:")
if n < 0:
    exit("n must be more than 0")

for i in range(0,n):
    a.append(randint(-15,15))

print(str(a))

for i in range (n):
    if a[i] < 0:
        count += 1

print("count is " + str(count))