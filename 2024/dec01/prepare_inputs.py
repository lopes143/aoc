ids = open('input.txt', 'r')
id1 = []
id2 = []
for line in ids:
    x = line.split('   ')
    id1.append(int(x[0][:5]))
    id2.append(int(x[1][:5]))

id1=sorted(id1)
id2=sorted(id2)