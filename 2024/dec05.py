inp = open('5.txt').read().split('\n')
#Prepare inputs
rules = []
instructions = []
rightInstructions = []
wrongInstructions = []
change = False
for i in inp:
    if i == '':
        change = True
    rules.append(i) if not change else instructions.append(i)

del(instructions[0]) #remover o ''
rules = [i.split('|') for i in rules]
instructions = [i.split(',') for i in instructions]
for i in rules:
    for j in range(len(i)):
        i[j] = int(i[j])
for i in instructions:
    for j in range(len(i)):
        i[j] = int(i[j])

def check_valid(rule, instruction, num):
    for i in range(len(instruction)):
        if instruction[i] == num:
            if rule[1] in instruction[:i]:
                return False
    return True

#Challenge 1
for i in instructions:
    valid = True
    for j in range(len(i)):
        valueToCheck = i[j]
        for k in rules:
            if valueToCheck == k[0]:
                if check_valid(k, i, i[j]):
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

#Challenge 2

def check_all_rules(rules, instruction):
    for i in rules:
        if not check_valid(i, instruction, i[0]):
            return False
    return True

def determine_wrong_rules(rules, instruction):
    wrongRules = []
    for i in rules:
        if not check_valid(i, instruction, i[0]):
            wrongRules.append(i)
    return wrongRules

def flip(rule, instruction):
    a = instruction.copy()
    for i in range(len(a)):
        if a[i] == rule[0]:
            if rule[1] in a[:i]:
                a[i] = rule[1]
                a[a.index(rule[1])] = rule[0]
                return a
    return a

fixedOrders = []
for i in wrongInstructions:
    fixed = False
    tempInstruction = i.copy()
    while not fixed:
        wrongRules = determine_wrong_rules(rules, tempInstruction)
        tempInstruction = flip(wrongRules[0], tempInstruction)
        if check_all_rules(rules, tempInstruction):
            fixedOrders.append(tempInstruction)
            fixed = True
        

middleCount=0
for i in fixedOrders:
    middleCount+=i[int((len(i)/2)-0.5)]

print('Middle elements sum after fixing (challenge 2):', middleCount)
#Right answer: 



















# for i in wrongInstructions: 
#     fixed = False
#     for j in range(len(i)): 
#         if fixed:
#             break
#         for k in rules:
#             if fixed:
#                 break
#             if i[j] == k[0]:
#                 beforeValues = i[:j]
#                 for l in range(len(beforeValues)):
#                     if fixed:
#                         break
#                     if beforeValues[l] == k[1]:
#                         i[l] = i[j]
#                         i[j] = k[1]
#                         checkFlag = True
#                     for allRules in rules:
#                         if not check_valid(allRules, i, i[j]):
#                             checkFlag = False
#                             break
#                     if checkFlag:
#                         fixed = True
#                         fixedOrders.append(i)
#                         break
                                                       
# for i in wrongInstructions: #Wrong instructions
#     valid = False #If the instructionn is fixed correctly, this flag will be changed to True
#     for j in range(len(i)): 
#         #The instructions might have both right and wrong orders
#         #So we'll have to check all values again for wrong orders
#         valueToCheck = i[j]
#         for k in rules:
#             if valueToCheck == k[0]:
#                 nextValue = k[1]
#                 beforeValues = i[:j]
#                 if nextValue in beforeValues:                   #If the second value is before the first value
#                     valuesToFlip = [valueToCheck, nextValue]    #Create a list with the two values to flip, the first value is our current's and the second is what is making it invalid
#                     i[j] = valuesToFlip[1]                      #So the first value (current's) will be the second value (what is making it invalid)
#                     for l in range(len(beforeValues)):          #We need to find the index of the value that is making it invalid
#                         if beforeValues[l] == valuesToFlip[0]:  #If we had found...
#                             i[l] = valuesToFlip[0]              #... it will become the current's