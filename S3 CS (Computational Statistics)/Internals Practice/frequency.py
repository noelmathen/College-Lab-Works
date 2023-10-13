with open("filefreq.txt","w+") as f:
    f.write(input("Enter string: "))
    f.seek(0)
    contents=f.read()
    data=contents.split()
    countmax=0
    word=""
    for i in data:
        cnew=0
        for j in data:
            if(i==j):
                cnew+=1
            if(cnew>countmax):
                countmax=cnew
                word=i
    print("\nThe most common word is:",word,". It appears",countmax,"times")

