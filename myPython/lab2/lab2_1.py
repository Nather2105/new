import math
print('put e')
e = input()
print('put a')
a = input()
print('put x')
x = input()

fact = 1
sum = 0
k = 0
while sum < e :
    k += 1
    top = math.sin(x**k)
    fack = fack * (2*k) * (2*k-1)
    bot = (a**(2*k)*fact)
    sum+= top/bot

print('sum =' + str(sum))
print('count = ' + str(k))