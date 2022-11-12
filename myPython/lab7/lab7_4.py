try:
    n = int(input("input n:"))
except ValueError:
    exit('error')

try:
    x = float(input("input x:"))
except ValueError:
    exit('error')
    
        
if n < 0:
    exit('error')

def generator(x,n):
    for i in range (1,n+1):
        yield float((i*x)**i)
    

func = generator(x,n)
suma = 0
for i in range (1,n+1):
    suma += next(func)

print("sum is " + str(suma))

    