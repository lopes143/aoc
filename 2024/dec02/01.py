inp = open('input.txt', 'r')

safeCount=0
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

for line in inp:
    currentLine = [int(x) for x in line.split(' ')]
    safeCount+=1 if check_line(currentLine) else 0

print('Safe Reports (challenge 1):', safeCount)
#Right answer: 306