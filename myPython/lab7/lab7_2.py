from copy import copy


def GetSymbol(d):
    return str(d)


def GetDigit(c):
    try:
        return int(c)
    except ValueError:
        return -1


def AddDigit(n1, n2, p):
    k = n1 + n2 + p
    print(n1 + n2)
    additional_n1_n2 = n1 + n2
    p_toprint = p
    print(p)
    if k > 9:
        k_proc_10 = k % 10
        k_dil_10 = int(k / 10)
        return [k % 10, int(k / 10)]

    if k < -9:
        k_proc_10 = -k % 10
        k_dil_10 = int(k / 10)
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
    n = max(len(s1), len(s2)) - 1
    p = 0
    while (n >= 0):
        n1 = str(s1o + s1[n])
        n1 = GetDigit(n1)
        n2 = str(s2o + s2[n])
        n2 = GetDigit(n2)
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
s1 = '-297'
s2 = '-123'
AddColumn(s, s1, s2)