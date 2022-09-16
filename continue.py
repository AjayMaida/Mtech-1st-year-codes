#loop to print even number between 0 to 10
for i in range(10):
    if i%2!=0:
        continue
    print(i)

print("\n\nlalala lala...\n\n")
#loop to print odd number between 0 to 0
for i in range(10):
    if i%2==0:
        continue
    print(i)

#demostration of pass statement
#it is just line ; in c
# it instruct the compiler to do nothing
# it is null statementi =0 
if i==0:
    pass#do nothing
print("tested pass statement! ")