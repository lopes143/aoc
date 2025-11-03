inp = open('../input.txt', 'r')
lines = inp.readlines()

howManyCols = len(lines[0])
howManyLines = len(lines)

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