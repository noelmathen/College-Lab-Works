rowname=c("row1","row2","row3","row4","row5")
colname=c("col1","col2","col3")
mat=array(seq(100,200,2),dim=c(5,3,2),dimnames=list(rowname,colname))
print(mat)   