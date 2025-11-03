import aux04 as aux

XmasCount=0
for linh in range(0, aux.howManyLines+1):
    for coln in range(0, aux.howManyCols+1):
        XmasCount+=1 if aux.check_horizontal(aux.lines, linh, coln) else 0
        XmasCount+=1 if aux.check_vertical(aux.lines, linh, coln) else 0
        XmasCount+=1 if aux.check_diagonal(aux.lines, linh, coln) else 0
        XmasCount+=1 if aux.check_antidiagonal(aux.lines, linh, coln) else 0

print("XMAS Count (Challenge 1):", XmasCount)
#Right answer: 2557