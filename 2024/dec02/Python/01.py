import aux02 as aux

inp = open('../input.txt', 'r')

safeCount=0

for line in inp:
    currentLine = [int(x) for x in line.split(' ')]
    safeCount+=1 if aux.check_line_new(currentLine) else 0

print('Safe Reports (challenge 1):', safeCount)
#Right answer: 306