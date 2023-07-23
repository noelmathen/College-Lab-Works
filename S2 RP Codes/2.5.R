#Matrix 3x3
rowname=c("row1", "row2", "row3")
colname=c("col1", "col2", "col3")
N<- matrix(c(1:9),nrow=3,ncol=3,byrow=TRUE,dimnames=list(rowname,colname))
print("The array is: ")
print(N)

t <- t(N)
print("The transpose array is: ")
print(t)
a=c(t)
print("The object into which the matrix is saved is: ")
print(a)
