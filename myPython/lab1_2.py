
x = input("input x:")
y = input("input y:")
z = input("input z:")
u = input("input u:")
if (u == 1):
    if (y > z and y < x):
        f = y
    elif(y < z and z < x):
        f = z
    else:
        f = x
    # f = min(x, max(y,z))     
else:
    if (x < y):
        f = x
    else:
        f = y
    # f = min(x,y)
print("f = " + str(f))