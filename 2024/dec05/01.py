import prepare_inputs as inp

rightInstructions = []
wrongInstructions = []

for i in inp.instructions:
    valid = True
    for j in range(len(i)):
        valueToCheck = i[j]
        for k in inp.rules:
            if valueToCheck == k[0]:
                if inp.check_valid(k, i, i[j]):
                    continue
                else:
                    valid = False
                    break
    rightInstructions.append(i) if valid else wrongInstructions.append(i)

middleCount=0
for i in rightInstructions:
    middleCount+=i[int((len(i)/2)-0.5)]

print('Middle elements sum (challenge 1):', middleCount)
#Right answer: 5747