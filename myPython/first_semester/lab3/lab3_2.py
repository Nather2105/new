from random import randint

n = input("input n:")
if n < 1:
    exit("error, n must be more than 1")
    
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


ma = max(odd_max)
mi = min(even_min)
print('max from odds is ', ma)
print('min from evens is ', mi)
print('sum is ', (ma+mi))
