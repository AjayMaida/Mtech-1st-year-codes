text =input("enter your text\n")
if("make a lot of money " in text):
    Spam=True
elif("buy Now" in text):
    spam=True
elif("click this " in text):
    spam=True
elif("subscribe this" in text):
    spam=True
else:
    spam=False

if(spam):
    print("this text is spam")
else:
    print("This test in not spam")