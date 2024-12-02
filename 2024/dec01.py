ids = open('1.txt', 'r')
id1 = []
id2 = []
for line in ids:
    x = line.split('   ')
    id1.append(int(x[0][:5]))
    id2.append(int(x[1][:5]))

id1=sorted(id1)
id2=sorted(id2)
#Listas ordenadas
totalDistance = 0
for i1,i2 in zip(id1,id2):
    totalDistance += abs(i1-i2)

print('Total Distance (challenge 1):', totalDistance)
appearance, timesFound = 0, 0
for i1 in id1:
    for i2 in id2:
        if i1==i2:
            timesFound+=1
    appearance+= i1*timesFound
    timesFound=0
print('Similarity score (challenge 2):', appearance)