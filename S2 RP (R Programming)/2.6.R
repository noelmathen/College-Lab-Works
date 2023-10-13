#Matrix 3x3
print("Matrix N") 
rowname=c("row1", "row2", "row3")
colname=c("col1", "col2", "col3")
N<- matrix(c(1:9),nrow=3,ncol=3,byrow=TRUE,dimnames=list(rowname,colname))
print(N)

# Matrix 3x2
print("Matrix M") 
rowname=c("row1", "row2", "row3")
colname=c("col1", "col2")
M<- matrix(c(1:6),nrow=3,ncol=2,byrow=TRUE,dimnames=list(rowname,colname))
print(M)

# Matrix Multiplication 3x2
print("Matrix N x M") 
t=  N %*% M
print(t)

#saving into an object
print("The obect into which the matrix is saved is: ")
matrix_mul =c(t)
print(matrix_mul)