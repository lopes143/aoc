import aux05 as aux

fixedOrders = []
rightInstructions = []
wrongInstructions = []

for i in aux.instructions:
    valid = True
    for j in range(len(i)):
        valueToCheck = i[j]
        for k in aux.rules:
            if valueToCheck == k[0]:
                if aux.check_valid(k, i, i[j]):
                    continue
                else:
                    valid = False
                    break
    wrongInstructions.append(i) if not valid else None


for i in wrongInstructions:
    fixed = False
    tempInstruction = i.copy()
    while not fixed:
        wrongRules = aux.determine_wrong_rules(aux.rules, tempInstruction)
        tempInstruction = aux.flip(wrongRules[0], tempInstruction)
        if aux.check_all_rules(aux.rules, tempInstruction):
            fixedOrders.append(tempInstruction)
            fixed = True
        

middleCount=0
for i in fixedOrders:
    middleCount+=i[int((len(i)/2)-0.5)]

print('Middle elements sum after fixing (challenge 2):', middleCount)
#Right answer:5502 