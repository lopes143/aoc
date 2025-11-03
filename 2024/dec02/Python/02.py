import aux02 as aux

inp = open('../input.txt', 'r')

inp.seek(0)
safeCount=0
for line in inp:
    safeFound=False
    currentLine = [int(x) for x in line.split(' ')]
    if aux.check_line_new(currentLine):
        #A linha já é segura
        safeCount+=1
        continue
    for val in range(0, len(currentLine)):
        tempLine = currentLine.copy()
        del(tempLine[val])
        if aux.check_line_new(tempLine):
            #Esta sequência cria uma linha segura
            safeCount+=1
            break
        

print('Safe Reports after Problem Dampener (challenge 2):', safeCount)
#Right answer: 366