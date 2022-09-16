a=[2,'b'] # this is list
print(a)
print(a[1]) # gives 'b'
#we can change list by 
a[1]=3
print(a)
a=[1,"ajay",'a',2.22] # perfectly valid


#list slicing

friend=["ajay","dimple","anjali","asha",45]
print(friend[0:4])
print(friend[-5:])
l1=[3,5,2,1,0,4]
l1.sort() # this funtion return nothing ,it change in it
print(l1)
l1.index(3,8)
l1.append(6) # add at the end
l1.reverse()
l1.pop(3) # will delete element at index and return its value
l1.remove(21) #remove 21 from list if present


# tuples
#similar to list but we cannot update value of tuple
