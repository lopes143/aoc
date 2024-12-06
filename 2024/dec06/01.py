import prepare_inputs as inp
import time

ourTab = inp.inp.copy() #Then we need to create a copy of the input tab
guardPos = inp.find_guard(ourTab) #First we need to find the initial guard position
guardState = ourTab[guardPos[0]][guardPos[1]] #Variable to store current guard state

while inp.find_guard(ourTab) != None:
    if ourTab[guardPos[0]-1][guardPos[1]] == '#' and guardState == "^":
        guardState = ">"
        ourTab[guardPos[0]][guardPos[1]] = ">"
    elif ourTab[guardPos[0]][guardPos[1]+1] == '#' and guardState == ">":
        guardState = "v"
        ourTab[guardPos[0]][guardPos[1]] = "v"
    elif ourTab[guardPos[0]+1][guardPos[1]] == '#' and guardState == "v":
        guardState = "<"
        ourTab[guardPos[0]][guardPos[1]] = "<"
    elif ourTab[guardPos[0]][guardPos[1]-1] == '#' and guardState == "<":
        guardState = "^"
        ourTab[guardPos[0]][guardPos[1]] = "^"
    
    if guardState == "^":
        ourTab, guardPos = inp.go_up(ourTab, guardPos)
    elif guardState == "v":
        ourTab, guardPos = inp.go_down(ourTab, guardPos)
    elif guardState == "<":
        ourTab, guardPos = inp.go_left(ourTab, guardPos)
    elif guardState == ">":
        ourTab, guardPos = inp.go_right(ourTab, guardPos)

    print(ourTab)
    time.sleep(2) #We need to sleep for 1 second before moving the guard again