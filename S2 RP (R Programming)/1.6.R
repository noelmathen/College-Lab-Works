prime<-function(num)
{
  for (i in 1:num) 
  {
    flag=0
    for(j in 2:(i/2))
    {
      if(i%%j==0)
      {
        flag=flag+1
      }
    }
    if(flag==0)
    {
      print(i)
    }
  }
}
print("The prime numbers till 50 are: ")
print=prime(50)
