import prepare_inputs as inp

XmasCount=0
for linh in range(0, inp.howManyLines+1):
    for coln in range(0, inp.howManyCols+1):
        XmasCount+=1 if inp.check_horizontal(inp.lines, linh, coln) else 0
        XmasCount+=1 if inp.check_vertical(inp.lines, linh, coln) else 0
        XmasCount+=1 if inp.check_diagonal(inp.lines, linh, coln) else 0
        XmasCount+=1 if inp.check_antidiagonal(inp.lines, linh, coln) else 0

print("XMAS Count (Challenge 1): ", XmasCount)
#Right answer: 2557