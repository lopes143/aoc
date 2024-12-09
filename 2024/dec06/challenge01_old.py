input1 = open('input.txt', 'r').read().split('\n')
input2 = []
for i in input1: #convert each string to a list of characters
    a = []
    for i2 in i:
        a.append(i2)
    input2.append(a)
          
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
        tab[a[0]][a[1]] = "X"
        tab[a[0]-1][a[1]] = "^"
        return tab
    except: #The guard has left the map
        return None

def go_down(tab):
    #find "v" in tab
    try:
        a = find_guard(tab)
        tab[a[0]][a[1]] = "X"
        tab[a[0]+1][a[1]] = "v"
        return tab
    except: #The guard has left the map
        return None

def go_left(tab):
    #find "<" in tab
    try:
        a = find_guard(tab)
        tab[a[0]][a[1]] = "X"
        tab[a[0]][a[1]-1] = "<"
        return tab
    except: #The guard has left the map
        return None
            
def go_right(tab):
    #find ">" in tab
    try:
        a = find_guard(tab)
        tab[a[0]][a[1]] = "X"
        tab[a[0]][a[1]+1] = ">"
        return tab
    except: #The guard has left the map
        return None

ourTab = input2.copy() #Then we need to create a copy of the input tab
guardPos = find_guard(ourTab) #First we need to find the initial guard position
guardState = ourTab[guardPos[0]][guardPos[1]] #Variable to store current guard state

while guardPos != None:
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

    guardPos = find_guard(ourTab)

#Count Xs in tab
xCount = 0
for i in ourTab:
    xCount += i.count("X")
print('X Count (challenge 1):',xCount+1) #+1 because the final guard position is also counted as an X