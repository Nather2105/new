
start = ord('A')
finish = ord('X')


for i in range(start,finish+1):
    print(chr(i) + chr(i).lower(), end=' ')
    if (i % 8 == 0):
        print()

