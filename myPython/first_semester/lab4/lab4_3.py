import re

pattern = r'^[\w\d\._]+@[\w]+\.[\w]{2,}$'
string = input("input string: ") 
if (re.fullmatch(pattern, string)):
    print("yeah, this is email")
else:
    print("nope, this is not")