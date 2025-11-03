inp = open('../input.txt').read().split('\n')

rules = []
instructions = []
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