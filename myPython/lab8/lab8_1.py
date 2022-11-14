from os import path 
with open('numbs.txt', "r", encoding="utf-8") as file: 
    if path.exists("numbs.txt") and path.getsize("numbs.txt"): 
        s = [float(i) for i in file.readline().rstrip().split()] 
        print((s[-1])) 
    else: 
        print("Файл порожній!")