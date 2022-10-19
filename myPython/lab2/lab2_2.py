import math

print('put e')
e = input()

print('put x')
x = input()

af = x

for n in range(1,101):
  ase =  0.5*(af + x/af)  
  if (math.fabs(ase - af) < e):
    print('our answer is ' + str(ase))    
    print('index of our answer ' + str(n))
    print('element(n-1) is ' + str(af))    
    print('index of (n-1) ' + str(n-1))
        
    exit(1)
  af = ase

print('sorry i don\'t have a permission for numbers with index >100')