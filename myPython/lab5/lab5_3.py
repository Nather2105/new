from random import randint
seasons = {
    "Summer": ("June", "July", "August"),
    "Fall": ("September", "October", "November"),
    "Winter": ("December", "January", "February"),
    "Spring": ("March", "April", "May")
}
info = dict(zip([i for i in range(1, 13)], [randint(10,  200) for i in range(12)]))

seas = [] 
summer = (info[6] + info[7] + info[8]) / 3
fall = (info[9] + info[10] + info[11]) / 3
winter = (info[12] + info[1] + info[2]) / 3
spring = (info[3] + info[4] + info[5]) / 3

seas.append(summer)
seas.append(fall)
seas.append(winter)
seas.append(spring)

count = 0
for i in seasons.keys():
    print("avg for", i, "is", seas[count])
    count += 1