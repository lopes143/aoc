import prepare_inputs as inp
#Listas ordenadas
totalDistance = 0
for i1,i2 in zip(inp.id1,inp.id2):
    totalDistance += abs(i1-i2)

print('Total Distance (challenge 1):', totalDistance)
#Right answer: 1580061