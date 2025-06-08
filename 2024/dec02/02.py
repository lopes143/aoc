inp = open('input.txt', 'r')

def check_line(seq):
    leng = len(seq)
    differences = []
    safeVar=0
    for val in range(0, leng-1):
        differences.append(seq[val+1]-seq[val])  #A lista diferenças contém todas as variações da linha
    signal = 'increase' if differences[0] > 0 else 'decrease'  #O sinal é definido pela primeira variação
    for diff in differences:
            safeVar+=1 if ((signal=='increase' and diff>0) or (signal=='decrease' and diff<0)) and 1<=abs(diff)<=3 else 0
    return True if safeVar==leng-1 else False  #A linha só é seguro se todos os valores forem seguros

inp.seek(0)
safeCount=0
for line in inp:
    safeFound=False
    currentLine = [int(x) for x in line.split(' ')]
    if check_line(currentLine):
        #A linha já é segura
        safeCount+=1
        continue
    for val in range(0, len(currentLine)):
        tempLine = currentLine.copy()
        del(tempLine[val])
        if check_line(tempLine):
            #Esta sequência cria uma linha segura
            safeCount+=1
            break
        

print('Safe Reports after Problem Dampener (challenge 2):', safeCount)
#Right answer: 366