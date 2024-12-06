import prepare_inputs as inp

safeCount=0
for line in inp.inp:
    safeFound=False
    currentLine = [int(x) for x in line.split(' ')]
    if inp.check_line(currentLine):
        #A linha já é segura
        safeCount+=1
        continue
    for val in range(0, len(currentLine)):
        tempLine = currentLine.copy()
        del(tempLine[val])
        if inp.check_line(tempLine):
            #Esta sequência cria uma linha segura
            safeFound=True
            break
    if safeFound:
        #A linha é segura
        safeCount+=1

print('Safe Reports after Problem Dampener (challenge 2):', safeCount)
#Right answer: 366