from copy import copy


def GetSymbol(d):
    return str(d)


def GetDigit(c):
    try:
        return int(c)
    except ValueError:
        return '-1'


def AddDigit(n1, n2, p):
    k = n1 + n2 + p
    if k > 9:
        return [k % 10, int(k / 10)]

    if k < -9:
        return [-k % 10, int(k / 10)]
    
    if k >= -9 and k < 0:
        return [-k % 10, int(k / 10)]
    return k, 0


def AddColumn(s, s1, s2):
    if s1[0] == '-':
        s1o = '-'
        s1 = s1.replace('-', '')
    elif s1[0] == '+':
        s1o = '+'
        s1 = s1.replace('+', '')
    elif int(s1[0]) >= 0 and int(s1[0]) <= 9:
        s1o = '+'

    if (s2[0] == '-'):
        s2o = '-'
        s2 = s2.replace('-', '')
    elif s2[0] == '+':
        s2o = '+'
        s2 = s2.replace('+', '')
    elif int(s2[0]) >= 0 and int(s2[0]) <= 9:
        s2o = '+'
    
    # s1 = '-1917.12'
    # s2 = '-111.123'
    # 7
    len1 = len(s1) 
    len2 = len(s2)
    # print(s1.index('.'))
    # 4
    point1 = s1.find('.')
    point2 = s2.find('.')
    # 3
    if point1 > point2:
        zeros = point1 - point2 
        s2 = str(zeros*'0') +s2
        
    elif point1 < point2:
        zeros = point2 - point1 
        s1 = str(zeros*'0') +s1
        
    if len1 - point1 > len2 - point2:
        zeros = (len1 - point1) - (len2 - point2)
        s2 = s2 + str(zeros*'0')
        
    elif len1 - point1 < len2 - point2:
        zeros = (len2 - point2) - (len1 - point1)
        s1 = s1 + str(zeros*'0')
    
    n = max(len(s1), len(s2)) - 1
    p = 0
    while (n >= 0):
        n1 = str(s1o + s1[n])
        n1 = GetDigit(n1)
        n2 = str(s2o + s2[n])
        n2 = GetDigit(n2)
        if( n1 == '-1' and n2 == '-1'):
            s = '.' + s
            n -= 1
            continue
        
        dod = AddDigit(n1, n2, p)
        s = GetSymbol(dod[0]) + s
        p = dod[1]
        n -= 1

    if (p != 0):
        s = GetSymbol(p) + s
    operator_s = s[0]
    s = s.replace('-', '')
    if operator_s == '-':
        s = '-' + s
    
    
    print(s)


s = ''
s1 = '345'
s2 = '-456'
print(s1)
print(s2)
AddColumn(s, s1, s2)