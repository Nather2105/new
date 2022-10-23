from random import randint

a = []
count = 0
for i in range(0,10):
    a.append(randint(-15,15))

print(str(a))

for i in range (10):
    
    if a[i] < 0:
        count += 1

print("count is " + str(count))