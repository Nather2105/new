str1 = input("put string ")
c1 = ord(input("put c1 "))
c2 = ord(input("put c2 "))

rangee = len(str1)




for i in range(c1,c2+1):
    str1 = str1.replace(chr(i),"")

print(str1)

