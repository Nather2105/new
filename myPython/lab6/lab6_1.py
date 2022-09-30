x = float(input('input x:'))
epsilon = float(input('input epsilon:'))

assert abs(x) < 1 

y = 1
counter = 1
while (1):
    counter *= -x*x 
    y += counter
    if(y >= epsilon):
        break

print('epsilon is ', epsilon)
print('answer is ', y)
    
