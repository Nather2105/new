matrix = [[0.76, -0.5, -1.23, 0.34],
          [0.53, -0.73, 0.15, 1.26],
          [0.3, 0.42, -0.08, -0.81],
          [0.3, -0.27, -1, 2.18]]

array = [0.88, -0.5, -0.5, 5.25]


i = 3
j = 3
k = 3
while i >= 1:
    while j >= 1:
        changer = matrix[j-1][i] / matrix[i][i]
        print(changer)
        while k >= 0:
            matrix[j-1][k] = matrix[j-1][k] - (matrix[i][k] * changer)
            k -= 1
        print(array[j-1])
        array[j-1] = array[j-1] - (array[i] * changer)  
        print(array[j-1])
        j -= 1
        k = 3
        print(array)
    i -= 1
    j = i
print(matrix)
              

ans = []
i = 0
j = 0
sum1 = 0 
while i <= 3:
    while j < i:
        sum1 += ans[j] * matrix[i][j]       
        j += 1  
            
    x = (array[i] - sum1) / matrix[i][i]
    ans.append(x)
    sum1 = 0
    j = 0
    i += 1
    
print(ans)