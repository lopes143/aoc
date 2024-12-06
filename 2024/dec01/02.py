import prepare_inputs as inp

appearance, timesFound = 0, 0
for i1 in inp.id1:
    for i2 in inp.id2:
        if i1==i2:
            timesFound+=1
    appearance+= i1*timesFound
    timesFound=0

print('Similarity score (challenge 2):', appearance)
#Right answer: 23046913