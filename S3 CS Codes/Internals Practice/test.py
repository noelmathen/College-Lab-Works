#5. Implements calculator with functions like add, subtract, multiply, divide, exponent etc.
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
  c=a//b
  return c

def exp(a,b):
    c=a**b
    return c
a=int(input("Enter number 1:"))
b=int(input("Enter number 2:"))
print("MENU")
print("1.ADD\t\t2.SUBTRACT\t\t3.MULTUPLY\t\t4.DIVIDE\t\t5.EPONENT")
y="yes"
while(y=="yes"):
  c=int(input("Enter your choice:"))
  if c==1:
    z=add(a,b)
    print(z)
  elif c==2:
    z=sub(a,b)
    print(z)
  elif c==3:
    z=mul(a,b)
    print(z)
  elif c==4:
    z=div(a,b)
    print(z)
  elif c==5:
    z=exp(a,b)
    print(z)
  else:
    print("Entered wrong option!")
  y=input("Do you want to continue?(yes/no):")
print("Thankyou!")
    