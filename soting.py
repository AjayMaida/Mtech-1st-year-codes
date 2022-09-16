a=[9,3,6,4,0,1,2,]
a.sort()
print(a)
print(a.count(9))

a=(1,7,2)
a[0]=9# error tuple oject does not support assignmemt
print(a.count(1)) 
print(a.index(1)) # retunrn  the first occurance of 1 in tuple