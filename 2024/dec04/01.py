import xmas

XmasCount=0
for linh in range(0, xmas.howManyLines+1):
    for coln in range(0, xmas.howManyCols+1):
        XmasCount+=1 if xmas.check_horizontal(xmas.lines, linh, coln) else 0
        XmasCount+=1 if xmas.check_vertical(xmas.lines, linh, coln) else 0
        XmasCount+=1 if xmas.check_diagonal(xmas.lines, linh, coln) else 0
        XmasCount+=1 if xmas.check_antidiagonal(xmas.lines, linh, coln) else 0

print("XMAS Count (Challenge 1): ", XmasCount)
#Right answer: 2557