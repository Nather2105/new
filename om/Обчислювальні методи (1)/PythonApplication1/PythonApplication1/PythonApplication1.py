def radok(string:str):
    list = []
    for i in range(10):
        if str(i) not in string:
            list.append(i)
    
    return list

def main():
    string = input("Enter: ")
    print(radok(string))

    if name == "main":
       main()
