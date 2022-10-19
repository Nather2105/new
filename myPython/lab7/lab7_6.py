from datetime import datetime

def time(func):
    def wrapper(*args):
        start = datetime.now()
        func(*args)
        print("wasted time =", datetime.now() - start) 
    return wrapper

@time
def teilor(epsilon, x):    
  y = 1
  counter = 1
  
  while (1):
    counter *= -x*x 
    y += counter
    if(y >= epsilon):
        break

  print('epsilon is', epsilon)
  print('answer is', y)
  
x = float(input('input x:'))
epsilon = float(input('input epsilon:'))

assert abs(x) < 1 
teilor(epsilon, x)    
