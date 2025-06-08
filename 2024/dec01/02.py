ids = open('input.txt', 'r')
id1 = []
id2 = []
for line in ids:
    x = line.split('   ')
    id1.append(int(x[0][:5]))
    id2.append(int(x[1][:5]))

appearance, timesFound = 0, 0
for i1 in id1:
    for i2 in id2:
        if i1==i2:
            timesFound+=1
    appearance+= i1*timesFound
    timesFound=0

print('Similarity score (challenge 2):', appearance)
#Right answer: 23046913