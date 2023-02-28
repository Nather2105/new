from os import path 
with open('numbers.txt', 'r', encoding='utf-8') as file1: 
    if path.exists("numbers.txt") and path.getsize("numbers.txt"): 
        s = [ str(i).rstrip() for i in file1.readlines() if i != '\n'] 
        s1 = list(dict.fromkeys(s)) 
        counter = 0 
        fl = 0 
        n = len(s) 
        for i in s1: 
            for j in s: 
                if (i == j): 
                    counter+=1 
                    fl += 1 
            if fl > 1: 
                counter+=1 
            fl = 0 
         
         
    else: 
        print("Файл 'res_squares.txt' порожній!") 
print("count of equal rows is " + str(counter - len(s1)))