import prepare_inputs as inp

XmasCount=0

for linh in range(1, inp.howManyLines-1):
    for coln in range(1, inp.howManyCols-2): #eliminar o \n
        if inp.lines[linh][coln] == "A":
            XmasCount+=1 if inp.x_mas(inp.lines, linh, coln) == ("MAS", "MAS") else 0
            XmasCount+=1 if inp.x_mas(inp.lines, linh, coln) == ("MAS", "SAM") else 0
            XmasCount+=1 if inp.x_mas(inp.lines, linh, coln) == ("SAM", "MAS") else 0
            XmasCount+=1 if inp.x_mas(inp.lines, linh, coln) == ("SAM", "SAM") else 0

print("X-MAS Count (challenge 2): ", XmasCount)
#Right answer: 1854