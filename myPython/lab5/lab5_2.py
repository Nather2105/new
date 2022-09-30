
n = int(input("input N: "))

# def compare_by_second(point):
#     return point[1]

teams = {}
for i in range(n):
    name = input('the name of team #' + str(i+1) + ': ')
    points = input('points of team #' + str(i+1) + ': ')

    teams[name] = int(points)
    
print(teams)

fl = 1
for i,j in teams.items():
  if fl:
    min1 = i
    fl = 0
    continue
  if teams[min1] > j:
    min1 = i
    

print(f"Name of team {min1}. Points of team {teams[min1]}")


    