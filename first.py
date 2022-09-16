# import os
# print(os.listdir()) 
a="ajay maida"
b=int("234567")
print(b+7)
c=input("please Enter your name : ")
print(type(c))
print(c)
c=input("enter your number:")
print("remainder ",c%2)
greeting ="good mornig"
name ="ajay "
c=greeting+name
# concate __ good moring ajay
#indexing start from 0 in python also
print(name[3])
#--> 'y'
#just like in any other language
name[3]='h' # won't work because you can access not change in it
print(name[0:3])
#print aja 0,1,2 three is not included in it
print(name[:4])
#is same as name[0:4]
print(name[0:])
#is same as name[0:5] ,, prit whole string
 #negative index in pytho
#  '''
#  used to find the last character without knowing the length 
#  of string
#  [a,j,a,y]
#  0,1,2,3
#  -4,-3,-2-,-1
#  -1 is the last character index
#  print(name[-4,-1]) is same as print(name[0,4])
#  '''
print(name[0:4:2])
 #2 is skip value here
 #ajaymaida
 #output will be == aaM skiping every second character


#   String functions
# 1.len
print(len(name))
print(name.endswith('a')) # is my string ending with last character or word as we are giving for check
print(name.cound("a")) #cound character 'a' in string
print(name.count("hello")) #count the occerance of string "hello" in string
print(name.capitalize()) #make first characte as capital latter
print(name.find("hey")) # find the occuring string and gives its possition
print(name.replace("hello","hey")) # replace all "hello " with "hey"
#to print \ we need to print \\
name =input("enter your name\n")
print("Good Afternoon,",name)
print("Good Afternoon,"+name) #many ways to do it

letter =''' dear<|name|>,
you are selected !
we are happy to inform you about your selection in our coding family!
<|date|>'''
name=input("enter your name")
date=input("enter todays date")
letter=letter.replace("<|name|>",name)
letter=letter.replace("<|date|>",date)
a=[1,2,3,4,5,6,7]

