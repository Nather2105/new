def rec(number):
    if(number/10 == 0):
        return number
    num = number % 10
    number-=num
    past = rec(number/10)
    if num > past :
        return num
    else:
        return past

print(rec(912332405034523408))
    
