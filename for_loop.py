fruits=['Banana','Mangoes','Watermalon','Grabes']
for item in fruits:
    print(item)

for i in range(10): #for printing sequence number
    print(i)
for i in range(1,10):
    print(i)
for i in range(1,10,2):
    print(i)

for i in range(2,8):
    print(i)
else: # this will exucute only when for loop successfully exicuted
    # means no brake statement exicuted
    print("out of for loop")

for i in range(1,8):
    print(i)
    if i==5:
        break
else:
    print("loop exicuted successfully !")