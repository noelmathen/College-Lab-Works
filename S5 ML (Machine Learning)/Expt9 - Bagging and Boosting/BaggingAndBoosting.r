install.packages("ipred")
library(ipred)
data(iris)
set.seed(123)
bagged_model<-bagging(Species ~., data = iris, nbagg=50)
predictions<-predict(bagged_model, newdata=iris)
table(predictions, iris$Species)


install.packages("gbm")
library(gbm)
data(iris)
iris$Species<-as.numeric(factor(iris$Species))
set.seed(123)
boosted_model<-gbm(Species~., data=iris, distribution = "multinomial", n.trees=100, interaction.depth=3, shrinkage=0.1)
predictions<-predict(boosted_model, newdata=iris, n.trees=100, type="response")
predicted_labels<-apply(predictions,1,which.max)
table(predicted_labels,iris$Species)
