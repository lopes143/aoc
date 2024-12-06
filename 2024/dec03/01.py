import prepare_inputs as inp

totalCount = 0
#O mámixo de caracteres é mul(XXX,XXX) : 12 caracteres

for i in range(0,len(inp.all)):
    if inp.all[i:i+3]=='mul': #Estamos perante uma multiplicação
        for i2 in range(3,13): #Seq à frente
            try:
                totalCount+= eval("inp."+inp.all[i:i+i2]) #concatenate "inp." to mul(XXX,XXX)
            except:
                continue
            else:
                break

print('Sum of multiplications (challenge 1):', totalCount)
#Right answer: 170807108