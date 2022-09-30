info = {
        '1': {'name' : 'vasya', 'surname' : 'gavrilyuk', 'year' : '1', 'points' : '90'},
        '2': {'name' : 'vlad', 'surname' : 'kriukov', 'year' : '2', 'points' : '100'},
        '3': {'name' : 'sasha', 'surname' : 'muhailyk', 'year' : '1', 'points' : '98'},
        '4': {'name' : 'masha', 'surname' : 'vylitkova', 'year' : '5', 'points' : '93'},
        '5': {'name' : 'dasha', 'surname' : 'yanchyshyn', 'year' : '1', 'points' : '53'},
        '6': {'name' : 'dima', 'surname' : 'petruk', 'year' : '3', 'points' : '83'},
        '7': {'name' : 'vadim', 'surname' : 'zaliznuy', 'year' : '3', 'points' : '89'},
        '8': {'name' : 'vova', 'surname' : 'dobruy', 'year' : '2', 'points' : '57'},
        '9': {'name' : 'lena', 'surname' : 'kozar', 'year' : '3', 'points' : '50'},
        '10': {'name' : 'yaroslav', 'surname' : 'mazur', 'year' : '4', 'points' : '48'}
        }

for i,j in info.items():
    if int(j['points']) >= 90:
        print(i + '.', j['name'], j['surname'],
        '(year of studying = ' + j['year'] + ') points = ' + j['points'])