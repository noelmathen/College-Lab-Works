library(ipred)

data("iris")
set.seed(123)

bag_model = bagging(Species~., iris, nbagg=50)
predictor = predict(bag_model, iris)

confusion_matrix=table(predictor, iris$Species)
confusion_matrix

accuracy = sum(diag(confusion_matrix))/sum(confusion_matrix)
accuracy


library(gbm)
data(iris)
set.seed(123)

bModel = gbm(Species~., iris, n.trees=100, distribution="multinomial", interaction.depth=3, shrinkage=0.1)
bPredictor = predict(bModel, iris, n.trees=100, type="response")
predictLabel = apply(bPredictor, 1, which.max)

confusion_matrix = table(iris$Species, predictLabel)
confusion_matrix

