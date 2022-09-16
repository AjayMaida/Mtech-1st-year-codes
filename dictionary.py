#dictionary and sets
#dictionary is a collection of key-value pairs
# it is unordered 

mydict={
    "fast": "in a Quick manner",
    "Ajay": "a coder",
    "marks": [1,2,3,4], #list in a dictionary as a value
    "anotherdict": {"ajay":"player"} # dictionary in dictinarry
}
print(mydict["Ajay"])
print(mydict["anotherdict"])
print(mydict["anotherdict"]["ajay"]) # like vector inside vector
#give 'player'
print(mydict["marks"][2]) # give 3


# methods of keys
#  print(list(mydict.keys())) #print all the keys of dictionary
#  print(mydict.values()) # prints the values of dictionary

updatedict={
    "lovish":"friend",
    "rahul": "friend",
    "Ajay": "friend", # since the same key is already present in 
                      # in mydict so ,it will replace it
}
mydict.update(updatedict) # update the dictonart by adding key-value from updatedict
print(mydict)
print(mydict.get("Ajay")) # returns none if this key is not present in dictionary 

print(mydict["Ajay"])
# if key is not presesnt this will give us a error
# this is the major difference
