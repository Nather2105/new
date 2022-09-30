slov = {}

string = input().split("=")

slov[string[1]] = string[0]

if '*' not in slov[string[1]]:
    print("false")
    exit(1)


if '+' in slov[string[1]] or '-' in slov[string[1]] or '/' in slov[string[1]]:
    print("false")
    exit(1)

print('true')
    
    
