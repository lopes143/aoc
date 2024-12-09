from tqdm import tqdm
a = open("input.txt", "r").read().strip().split("\n")
tab = [list(a2) for a2 in a]

line_number = len(tab)
column_number = len(tab[0])

guardFound = False
for i in range(line_number):
    for i2 in range(column_number):
        if tab[i][i2] in ('^', 'v', '<', '>'):
            guardFound = True
            initialX = i
            initialY = i2
            break
    if guardFound:
        break

x, y = initialX, initialY
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
currentDirection = 0
placesSeen = set()

while True:

    placesSeen.add((x, y))
    nextX = x + directions[currentDirection][0]
    nextY = y + directions[currentDirection][1]

    if not (0 <= nextX < line_number and 0 <= nextY < column_number):
        break

    if tab[nextX][nextY] == "#":
        currentDirection = (currentDirection + 1) % 4
    else:
        x, y = nextX, nextY

def will_loop(xx, yy):
    if tab[xx][yy] == "#":
        return False
    
    tab[xx][yy] = "#"
    x, y = initialX, initialY
    currentDirection = 0
    loopSeen = set()
    while True:
        if (x, y, currentDirection) in loopSeen:
            tab[xx][yy] = "."
            return True
        loopSeen.add((x, y, currentDirection))

        nextX = x + directions[currentDirection][0]
        nextY = y + directions[currentDirection][1]

        if not (0 <= nextX < line_number and 0 <= nextY < column_number):
            tab[xx][yy] = "."
            return False

        if tab[nextX][nextY] == "#":
            currentDirection = (currentDirection + 1) % 4
        else:
            x, y = nextX, nextY

loopCount = 0
for x1, x2 in tqdm(placesSeen):
    if x1 == initialX and x2 == initialY:
        #Cannot place obstacle where guard currently is
        continue
    if will_loop(x1, x2):
        loopCount += 1

print("Loop count (challenge 2):", loopCount)