# with open("file1.txt","w+") as f:
#     str=input("Enter string to be written: ")
#     f.write(str)
#     data=f.split()
#     print(data)

# Remove blank spaces from a file
with open("file1.txt","w+") as f1:
    strng=input("Enter data two be written: ")
    f1.write(strng)
    f1.seek(0)
    contents=f1.read()
    data=contents.split()
    with open("file2.txt","w+") as f2:
        for i in data:
            f2.write(i)





# f1=open("file1.txt","w+")
# f2=open("file2.txt","w+")
# strng=input("Enter data two be written: ")
# f1.write(strng)
# f1.seek(0)
# contents=f1.read()
# data=contents.split() 
# print(data)  