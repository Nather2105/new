str1 = ''

while(1):
    try:
      first = float(input("input first number: "))
        
    except ValueError:
      print('put a number, not string')  
      continue
    
    break

str1+=str(first)


while(1):
    try:
      operation = input("input operation: ")
      if(operation != '+' and operation != '-' and operation != '*' and operation != '/'):
          raise ValueError
    
    except ValueError:
      print('incorrect, put one from (+,-,*,/)')  
      continue
    
    break

str1+=str(operation)


while(1):
    try:
      second = float(input("input second number: "))
      if second == 0:
        raise ZeroDivisionError
        
    except ValueError:
      print('put a number, not string')  
      continue
    except ZeroDivisionError:
      print('imposible to div on zero')
      continue
    
    break

str1+=str(second)

print(eval(str1))
    

    
    
    