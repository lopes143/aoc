import prepare_inputs as inp

safeCount=0
for line in inp.inp:
    currentLine = [int(x) for x in line.split(' ')]
    safeCount+=1 if inp.check_line(currentLine) else 0

print('Safe Reports (challenge 1):', safeCount)
#Right answer: 306