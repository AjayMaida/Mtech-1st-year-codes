a=["ajay",1]
print(a)
a.append("maida")
print(a)
a.insert(2,"dimple")
print(a)
#remove specific element 
a.remove("ajay")
print(a)
a.reverse()
mylist=[1,4,0,2,3]
#sorted method is used for sorting list without making change in original list 
my_new_list=sorted(mylist)
print(mylist)
print(my_new_list)
my_merged_list=a+my_new_list
print(my_merged_list)
dic={"ajay":"cse","vijay":"chemical"}
print(dic)
print("\n")
for key,val in dic.items():
    print(key,val)
new_dic=dict(ajay="CSE",hello="hiii")
dic.update(new_dic)
print(dic)
print("\n")
for key,val in dic.items():
    print(key,val)