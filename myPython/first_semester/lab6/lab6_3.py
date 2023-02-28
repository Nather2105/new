inp1 = 0
runtime_error = 0
type_error = 0
value_error = 0
while (1):
  inp1 = input('input a number: ')
  if inp1 == 'stop':
      break
  try:
    inp1 = float(inp1)
    
    if(inp1 > 9):
        raise RuntimeError
    elif(inp1 < 0):
        raise TypeError
    elif(inp1 // 1 != inp1):
        raise ValueError
  
  except RuntimeError:
    runtime_error+=1

  except TypeError:
    type_error+=1
      
  except ValueError:
    value_error+=1

print('count of runtime errors =', runtime_error)
print('count of type errors =', type_error)
print('count of value errors =', value_error)