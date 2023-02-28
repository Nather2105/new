import math
try:
    e = float(input("input E:"))
except ValueError:
    exit('error')

try:
    x = float(input("input x:"))
except ValueError:
    exit('error')
    
if x < 0 or e < 0:
    exit('error') 

def generator(x,e):
    xl = float(x/4)
    fl = 0
    for i in range (1, 1000):
        if fl:
            exit()
        xr = float(1/4*(3*xl + x/(xl**2)))
        if(math.fabs(xr - xl) < e):
            yield (str(xr) + " - " + str(xl) + " < e" + "\n" + "indexes of numbers: " + str(i-1) + " and " + str(i))
            fl = 1
            
        else:
            yield (str(xr) + " - " + str(xl) + ">= e")
        xl = xr
        
    

func = generator(x,e)
for i in range (1, 1000):
    print(next(func))
