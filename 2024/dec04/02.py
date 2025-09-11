import xmas

XmasCount=0

for linh in range(1, xmas.howManyLines-1):
    for coln in range(1, xmas.howManyCols-2): #eliminar o \n
        if xmas.lines[linh][coln] == "A":
            XmasCount+=1 if xmas.x_mas(xmas.lines, linh, coln) == ("MAS", "MAS") else 0
            XmasCount+=1 if xmas.x_mas(xmas.lines, linh, coln) == ("MAS", "SAM") else 0
            XmasCount+=1 if xmas.x_mas(xmas.lines, linh, coln) == ("SAM", "MAS") else 0
            XmasCount+=1 if xmas.x_mas(xmas.lines, linh, coln) == ("SAM", "SAM") else 0

print("X-MAS Count (challenge 2): ", XmasCount)
#Right answer: 1854