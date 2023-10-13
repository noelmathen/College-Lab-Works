def add(a,b):
    c=a+b
    return c

def sub(a,b):
    c=a-b
    return c

def mul(a,b):
    c=a*b
    return c

def div(a,b):
    c=a/b
    return c

def exp(a,b):
    c=a**b
    return c

print("\nMENU\n\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n5. EXPONENT")

while(1):
    choice=int(input("\nEnter your choice: "))

    if choice==1:
        x=eval(input("Enter the first number: "))
        y=eval(input("Enter the second number: "))
        z=add(x,y)
        print(x,"+",y,"=",z)
    elif choice==2:
        x=eval(input("Enter the first number: "))
        y=eval(input("Enter the second number: "))
        z=sub(x,y)
        print(x,"-",y,"=",z)
    elif choice==3:
        x=eval(input("Enter the first number: "))
        y=eval(input("Enter the second number: "))
        z=mul(x,y)
        print(x,"*",y,"=",z)
    elif choice==4:
        x=eval(input("Enter the first number: "))
        y=eval(input("Enter the second number: "))
        z=div(x,y)
        print(x,"/",y,"=",z)
    elif choice==5:
        x=eval(input("Enter the first number: "))
        y=eval(input("Enter the second number: "))
        z=exp(x,y)
        print(x,"^",y,"=",z)
    elif choice==6:
        print("OHK BEI:)))")
        exit()
    else:
        print("INVALID CHOICE!")
