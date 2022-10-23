import re

string = input("put string ")

pattern = r'\d'
string = re.sub(pattern, '', string)
print(string)

