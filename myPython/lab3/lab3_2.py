from random import randint

n = input()
start = []
odd_max = [] 
even_min = []

for i in range(1, n+1):
    start.append(randint(-30,30))

print(str(start))

for i in range(1, n+1):
    if i % 2 == 0:
        even_min.append(start[i - 1])
    else:
        odd_max.append(start[i - 1])

print('max from odds is ', (max(odd_max)))
print('min from evens is ', (min(even_min)))
