input1 = open('../input.txt', 'r').read().split('\n')
input2 = []
for i in input1: #convert each string to a list of characters
    a = []
    for i2 in i:
        a.append(i2)
    input2.append(a)

ourTab = input2.copy()

def find_guard(tab):
    #find "^, v, <, >" in tab
    for i in range(len(tab)):
        for i2 in range(len(tab[i])):
            if tab[i][i2] in ('^', 'v', '<', '>'):
                return (i, i2)
    return None #return None if no guard is found

def go_up(tab):
    try:
        a = find_guard(tab)
        t = tab.deepcopy()
        if t[a[0]][a[1]-1] == "-" or t[a[0]][a[1]+1] == "-":
            t[a[0]][a[1]] = "+"
        else:
            t[a[0]][a[1]] = "|"
        if t[a[0]-1][a[1]] != "|":
            t[a[0]-1][a[1]] = "^"
        else:
            #We're in a loop
            return "loop"
        return t
    except: #The guard has left the map
        return None

def go_down(tab):
    #find "v" in tab
    try:
        a = find_guard(tab)
        if tab[a[0]][a[1]-1] == "-" or tab[a[0]][a[1]+1] == "-":
            tab[a[0]][a[1]] = "+"
        else:
            tab[a[0]][a[1]] = "|"
        tab[a[0]+1][a[1]] = "v"
        return tab
    except: #The guard has left the map
        return None

def go_left(tab):
    #find "<" in tab
    try:
        a = find_guard(tab)
        if tab[a[0]-1][a[1]] == "|" or tab[a[0]+1][a[1]] == "|":
            tab[a[0]][a[1]] = "+"
        else:
            tab[a[0]][a[1]] = "-"
        tab[a[0]][a[1]-1] = "<"
        return tab
    except: #The guard has left the map
        return None
            
def go_right(tab):
    #find ">" in tab
    try:
        a = find_guard(tab)
        if tab[a[0]-1][a[1]] == "|" or tab[a[0]+1][a[1]] == "|":
            tab[a[0]][a[1]] = "+"
        else:
            tab[a[0]][a[1]] = "-"
        tab[a[0]][a[1]+1] = ">"
        return tab
    except: #The guard has left the map
        return None


while True:
    guardPos = find_guard(ourTab)
    guardState = ourTab[guardPos[0]][guardPos[1]]

    try:    
        if guardState == "^":
            if ourTab[guardPos[0]-1][guardPos[1]] == '#':
                guardState = ">"
                ourTab[guardPos[0]][guardPos[1]] = ">"
        elif guardState == ">":
            if ourTab[guardPos[0]][guardPos[1]+1] == '#':
                guardState = "v"
                ourTab[guardPos[0]][guardPos[1]] = "v"
        elif guardState == "v":
            if ourTab[guardPos[0]+1][guardPos[1]] == '#':
                guardState = "<"
                ourTab[guardPos[0]][guardPos[1]] = "<"
        elif guardState == "<":
            if ourTab[guardPos[0]][guardPos[1]-1] == '#':
                guardState = "^"
                ourTab[guardPos[0]][guardPos[1]] = "^"
    except:
        #Guard has left the map
        break

    if guardState == "^":
        go_up(ourTab)
    elif guardState == "v":
        go_down(ourTab)
    elif guardState == "<":
        go_left(ourTab)
    elif guardState == ">":
        go_right(ourTab)
    else:
        break

#Count loops
loopCount = 0
for i in ourTab:
    loopCount += i.count("X")
print('Loop Count (challenge 2):',loopCount) #+1 because the final guard position is also counted as an X