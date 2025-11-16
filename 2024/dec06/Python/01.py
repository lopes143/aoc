a = open("../input.txt", "r").read().strip().split("\n")
tab = [list(a2) for a2 in a]

line_number = len(tab)
column_number = len(tab[0])

guardFound = False
for i in range(line_number):
    for i2 in range(column_number):
        if tab[i][i2] in ('^', 'v', '<', '>'):
            guardFound = True
            x = i
            y = i2
            break
    if guardFound:
        break

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
    
print("Places seen (challenge 1):", len(placesSeen))
#Right answer: 4665