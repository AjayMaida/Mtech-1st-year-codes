
sub1=int(input("enter first subject marks :"))
sub2=int(input("enter first subject marks :"))
sub3=int(input("enter first subject marks :"))
if(sub1<33 or sub2<33 or sub3<33):
    print("you are fail and you are hero! ")
elif(sub1+sub2+sub3)/3<40:
    print("you are fail , try again !")
else:
    print("badhai Ho londe !! tu pas ho gya ")
