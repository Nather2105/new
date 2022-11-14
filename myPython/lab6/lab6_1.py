epsilon = float(input('input epsilon:'))
while 1:
    try:
        x = float(input('input x:'))
        assert abs(x) < 1 
    except AssertionError:
        print("|x| must be < 1")
        continue 
    break

y = 1
counter = 1
while (1):
    counter *= -x*x 
    y += counter
    if(y >= epsilon):
        break

print('epsilon is ', epsilon)
print('answer is ', y)
    
