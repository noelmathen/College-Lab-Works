factors<-function(n)
{
  print("The factors of 100 are: ")
  for(i in 1:n)
  {
    if(n%%i==0)
    {
      print(i)
    }
  }
}
print=factors(100)
