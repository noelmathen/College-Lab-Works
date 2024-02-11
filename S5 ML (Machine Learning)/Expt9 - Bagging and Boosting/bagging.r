#install.packages("ipred")
library(ipred)

data(iris)
set.seed(123)

bagged_model<-bagging(Species ~., iris, nbagg=50)
predictions<-predict(bagged_model, iris)

confusion_matrix = table(predictions, iris$Species)
confusion_matrix
accuracy = sum(diag(confusion_matrix))/sum(confusion_matrix)
accuracy
