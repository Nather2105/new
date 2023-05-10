import numpy as np
import math
import matplotlib.pyplot as plt
import os
import random

'''
    Лабораторна робота №5
    Завдання 4
    
    функція для дослідження => cosh(x)

    тестовий приклад:
    a = -5
    b = 5
    step = 0.001
    n = 4

    !!! при збільшенні n похибка зменшується !!!

    !!! значення step, [a,b] та TEST_NUM взаємопов'язані !!!
'''

TEST_NUM = 10000 # кількість випадковим чином згенерованих точок


def mc_square(y1, y2, xmin, xmax, ymin, ymax):
    '''
    Обчислює площу між функціями f1 та f2 методом Монте-Карло.

    xmin, xmax, ymin, ymax - границі прямокутника,
    у якому повністю розміщено нашу фігуру.
    '''

    print("\nx_min = {}, x_max = {}, \ny_min = {}, y_max = {}".format(xmin, xmax, ymin, ymax))

    print("\nОбчислення Методом Монте-Карло\n")

    x = np.random.uniform(xmin, xmax, TEST_NUM)  # масив координат x
    print("\nМасив випадковим чином згенерованих координат x")
    print(x)

    y = np.random.uniform(ymin, ymax, TEST_NUM)  # масив координат y
    print("\nМасив випадковим чином згенерованих координат y")
    print(y)
    
    count_in = len(y[np.logical_and(y1 <= y, y <= y2)])# кількість точок,
                                                       # що потрапили в область
    
    print("Кількість точок (x,y), що потрапили до замальованої області => ",
          count_in)                                                       
    
    s = (count_in * ((xmax - xmin) * (ymax - ymin))) / TEST_NUM   # площа
    print("Площа замальованої синім кольором фігури s = ", s)
    
    return s


def myfun(n,a,b,step):
    '''
    y1 => розклад в ряд Тейлора
            функції cosh(x)
    '''
    len=int((b-a)/step)
    y = np.zeros(len,dtype=float)
    x=float(a)
    for i in range(len):
        sum=1.0
        for j in range(1,n,2):
            sum=sum+((x**(j+1))/math.factorial(j+1))
        y[i]=sum
        x=x+step
    return y

def mathfun(a,b,step):
    '''
    y2 => np.cosh(x)
           (за даними бібліотеки numpy)
    '''
    len = int((b - a) / step)
    y = np.zeros(len, dtype=float)
    x = float(a)
    for i in range(len):
        y[i] = np.cosh(x)
        x = x + step
    return y

def g(y1,y2):
    '''
    g => math.fabs(y1-y2)
    '''
    n=len(y1)
    y=np.zeros(n)
    for i in range(n):
        y[i]=math.fabs(y1[i]-y2[i])
    return y

a=float(input("Уведіть  ліву межу відрізка (a): "))
b=float(input("Уведіть праву межу відрізка (b): "))
step=float(input("Уведіть крок (step): "))
n=int(input("Уведіть кількість членів розкладу в ряд Тейлора (n): "))

x=np.arange(a,b,step)
print("\nМасив вузлів по вісі абсцис (x) =>\n", x)

y1=myfun(n,a,b,step)
print("Масив значень функції, розрахованої за розкладом у ряд Тейлора (y1) => \n", y1)

y2=mathfun(a,b,step)
print("Масив значень функції, розрахованої за бібліотечними даними np.cosh (y2) => \n", y2)

plt.xlabel('x')                 #встановити надпис на осі x
plt.ylabel('y')                 #встановити надпис на осі y

plt.plot( x, y1, color="red", label = myfun.__doc__ )
plt.plot( x, y2, color="green", label = mathfun.__doc__ )
plt.fill_between( x, y1, y2, color="blue" )

y3=g(y1,y2)
plt.plot( x, y3, color="yellow", label = g.__doc__ )

plt.legend(loc = 'best')        #встановити легенду

xmin=a
xmax=b

ymin = min(y1)
ymax = max(y2)

s = mc_square(y1, y2, xmin, xmax, ymin, ymax)

dev = math.sqrt( s/((xmax - xmin) * (ymax - ymin)) )
print("Похибка = {}".format(dev))

plt.show()
