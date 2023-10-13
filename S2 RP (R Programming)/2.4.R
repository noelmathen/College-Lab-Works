#Matrix 1
rowname=c("row1","row2","row3","row4","row5")
colname=c("col1","col2","col3","col4")
print("Matrix 1 - 5x4")
mat=matrix(c(1:20),nrow=5,ncol=4,byrow=TRUE,dimnames=list(rowname,colname))
print(mat)

#Matrix 2
rowname=c("row1","row2","row3")
colname=c("col1","col2","col3")
print("Matrix 2 - 3x3")
mat=matrix(c(1:9),nrow=3,ncol=3,byrow=TRUE,dimnames=list(rowname,colname))
print(mat)

#Matrix 3
rowname=c("row1","row2")
colname=c("col1","col2")
print("Matrix 3 - 2x2")
mat=matrix(c(1:4),nrow=2,ncol=2,byrow=TRUE,dimnames=list(rowname,colname))
print(mat)
