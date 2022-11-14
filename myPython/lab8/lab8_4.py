from os import path 
 
 
def five_and_chip(base): 
    output = set() 
    for i, j, k in sorted(base): 
        if int(j) <= 400 and int(k) <= 5: 
            output.add(f"name of toy is {i}, price is {j}, for children older than {k} years old ") 
    return output 
 
 
with open('toys.txt', 'r', encoding='utf-8') as file1: 
    if path.exists('toys.txt') and path.getsize('toys.txt'): 
        s = [ str(i).rstrip().split() for i in file1 if i != '\n']  
        print(*sorted(five_and_chip(s)), sep="\n") 
    else: 
        print("Файл порожній!")