inp = open('4.txt', 'r')
lines = inp.readlines()
howManyCols = len(lines[0])
howManyLines = len(lines)
XmasCount=0

def check_horizontal(lis, lin, col):
    try:
        word=""
        for i in range(0,4):
            word += lis[lin][col+i]
        return word in ("XMAS","SAMX")
    except:
        return False

def check_vertical(lis, lin, col):
    try:
        word=""
        for i in range(0,4):
            word += lis[lin+i][col]
        return word in ("XMAS","SAMX")
    except:
        return False
    
def check_diagonal(lis, lin, col):
    try:
        word = ""
        for i in range(0,4):
            word += lis[lin+i][col+i]
        return word in ("XMAS","SAMX")
    except:
        return False

def check_antidiagonal(lis, lin, col):
    try:
        word =""
        for i in range(0,4):
            a = col-i
            if a<0:
                raise ValueError
            word += lis[lin+i][a]
        return word in ("XMAS","SAMX")
    except:
        return False

for linh in range(0, howManyLines+1):
    for coln in range(0, howManyCols+1):
        XmasCount+=1 if check_horizontal(lines, linh, coln) else 0
        XmasCount+=1 if check_vertical(lines, linh, coln) else 0
        XmasCount+=1 if check_diagonal(lines, linh, coln) else 0
        XmasCount+=1 if check_antidiagonal(lines, linh, coln) else 0

print("XMAS Count (Challenge 1): ", XmasCount)

inp.seek(0)
XmasCount=0

def x_mas(lis,lin,col):
    # 1 . .    . . 3
    # . 2 .    . 2 .
    # . . 3    1 . .
    word1=""
    word2=""
    for i in range(-1, 2):
        word1+=lis[lin+i][col+i]
        word2+=lis[lin-i][col+i]
    return (word1, word2)


for linh in range(1, howManyLines-1):
    for coln in range(1, howManyCols-2): #eliminar o \n
        if lines[linh][coln] == "A":
            XmasCount+=1 if x_mas(lines, linh, coln) == ("MAS", "MAS") else 0
            XmasCount+=1 if x_mas(lines, linh, coln) == ("MAS", "SAM") else 0
            XmasCount+=1 if x_mas(lines, linh, coln) == ("SAM", "MAS") else 0
            XmasCount+=1 if x_mas(lines, linh, coln) == ("SAM", "SAM") else 0

print("X-MAS Count (challenge 2): ", XmasCount)
