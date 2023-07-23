#3. Search an element in a list
lst=[]
n=eval(input("Enter the number of elements in the list: "))
for i in range(0,n):
    x=eval(input("Enter element: "))
    lst.append(x)
print("The list is: ",lst)
count=0
y=eval(input("Enter the element to be searched: "))
for i in lst:
    count += 1
    if(y==i):
        print(y," is present in list. Position =",count)
        break
else:
    print(y," is not present in list")

