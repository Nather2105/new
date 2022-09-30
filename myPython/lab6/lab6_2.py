string = (input('input string: '))

count = 0
suma = 0
for i in string:  
  try:
    suma+=int(i)
    
  except ValueError:
    count+=1
    continue
print('sum is', suma)
print('count of letters is', count)