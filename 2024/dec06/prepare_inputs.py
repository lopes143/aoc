inpu = open('input.txt', 'r').read().split('\n')
inp = []
for i in inpu: #convert each string to a list of characters
     for i2 in i:
            inp.append([i2])
          

guardTypes = ("^", "v", "<", ">")

def find_guard(tab):
    #find "^, v, <, >" in tab
    for i in range(len(tab)):
        for i2 in range(len(tab[i])):
            if tab[i][i2] in guardTypes:
                return (i, i2)
    return None #return None if no guard is found

def get_pos_value(tab, pos):
    return tab[pos[0]][pos[1]]


def go_up(tab, pos):
    #find "^" in tab
    try:
        if tab[pos[0]][pos[1]] not in guardTypes:
                return None
        
        newPos = (pos[0]-1, pos[1])
        newTab = tab.copy()

        newTab[pos[0]][pos[1]] == "X"
        newTab[newPos[0]][newPos[1]] == "^"

        return (newTab,newPos)
    except: #The guard has left the map
        return (newTab,newPos)


def go_down(tab, pos):
    #find "v" in tab
    try:
        if tab[pos[0]][pos[1]] not in guardTypes:
                return None
        
        newPos = (pos[0]+1, pos[1])
        newTab = tab.copy()

        newTab[pos[0]][pos[1]] == "X"
        newTab[newPos[0]][newPos[1]] == "v"

        return (newTab,newPos)
    except: #The guard has left the map
        return (newTab,newPos)


def go_left(tab, pos):
    #find "<" in tab
    try:
        if tab[pos[0]][pos[1]] not in guardTypes:
                return None
        
        newPos = (pos[0], pos[1]-1)
        newTab = tab.copy()

        newTab[pos[0]][pos[1]] == "X"
        newTab[newPos[0]][newPos[1]] == "<"

        return (newTab,newPos)
    except: #The guard has left the map
        return (newTab,newPos)
            

def go_right(tab, pos):
    #find ">" in tab
    try:
        if tab[pos[0]][pos[1]] not in guardTypes:
                return None
        
        newPos = (pos[0], pos[1]+1)
        newTab = tab.copy()

        newTab[pos[0]][pos[1]] == "X"
        newTab[newPos[0]][newPos[1]] == ">"

        return (newTab,newPos)
    except: #The guard has left the map
        return (newTab,newPos)