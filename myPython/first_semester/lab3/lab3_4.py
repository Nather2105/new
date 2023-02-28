from random import randint

a = tuple([randint(0, 5) for i in range(10)] )
b = tuple([randint(-5, 0) for i in range(10)] )

print(a)
print(b)

c = a + b

count = c.count(0)
print('count is ' + str(count))
print(c)
