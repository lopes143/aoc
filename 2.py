inp = open('2.txt', 'r')
safeCount=0
for line in inp:
    line = [int(x) for x in line.split(' ')]
    differences = []
    leng = len(line)
    for val in range(0, leng-1):
        differences.append(line[val+1]-line[val])
        #A lista differences contém todas as variações da linha
    signal = 'increase' if differences[0] > 0 else 'decrease'
    #O sinal é definido pela primeira variação
    safeVar=0
    for diff in differences:
            safeVar+=1 if ((signal=='increase' and diff>0) or (signal=='decrease' and diff<0)) and 1<=abs(diff)<=3 else 0
            #É seguro se a variação for igual à primeira e estar dentro dos valores seguros
    if safeVar==leng-1:
        safeCount+=1
    #A linha só é seguro se todos os valores forem seguros
print(safeCount)