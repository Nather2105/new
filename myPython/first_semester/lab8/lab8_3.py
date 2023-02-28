from os import path 
 
 
def thirty_and_more(base): 
    output = set() 
    for i, j in sorted(base.items()): 
        if int(j[1]) == 1 and int(j[2]) >= 30: 
            output.add(i) 
    return output 
 
 
with open('last_name.txt', 'r', encoding='utf-8') as file1, open('baggages_info.txt', 'r', encoding='utf-8') as file2: 
    if path.exists('last_name.txt') and path.exists('baggages_info.txt') and path.getsize('last_name.txt') and \ 
            path.getsize('baggages_info.txt'): 
        s = dict(zip([i.rstrip() for i in file1], [i.rstrip().split() for i in file2])) 
        print(*sorted(thirty_and_more(s)), sep="\n") 
    else: 
        print("Файл порожній!")