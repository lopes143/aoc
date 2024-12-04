inp = open('3.txt', 'r')
all = inp.read()

#Challenge 1
totalCount = 0
#O mámixo de caracteres é mul(XXX,XXX) : 12 caracteres
def mul(n1,n2):
    return n1 * n2

for i in range(0,len(all)):
    if all[i:i+3]=='mul': #Estamos perante uma multiplicação
        for i2 in range(3,13): #Seq à frente
            try:
                totalCount+= eval(all[i:i+i2])
            except:
                continue
            else:
                break

print('Sum of multiplications (challenge 1):', totalCount)

#Challenge 2
inp.seek(0)
totalCount = 0
do = True

for i in range(0,len(all)):
    if all[i:i+4]=='do()':
        do = True
    if all[i:i+7]=="don't()":
        do = False
    if all[i:i+3]=='mul' and do: #Estamos perante uma multiplicação e podemos resolver
        for i2 in range(3,13): #Seq à frente
            try:
                totalCount+= eval(all[i:i+i2])
            except:
                continue
            else:
                break

print('Sum of enabled multiplications (challenge 2):', totalCount)

