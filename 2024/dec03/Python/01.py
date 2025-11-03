inp = open('../input.txt', 'r')
all = inp.read()

def mul(n1,n2):
    return n1 * n2

totalCount = 0
#O mámixo de caracteres é mul(XXX,XXX) : 12 caracteres

for i in range(0,len(all)):
    if all[i:i+3]=='mul': #Estamos perante uma multiplicação
        for i2 in range(3,13): #Seq à frente
            try:
                totalCount+= eval(all[i:i+i2]) #mul(XXX,XXX)
            except:
                continue
            else:
                break

print('Sum of multiplications (challenge 1):', totalCount)
#Right answer: 170807108