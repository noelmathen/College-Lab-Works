library(rpart)
library(rpart.plot)
titanic = read.csv("titanic.csv")
titanic = titanic[, c("Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Survived")]

sum(is.na(titanic))
titanic = na.omit(titanic)

titanic$Sex = as.factor(titanic$Sex)
dt_model = rpart(Survived~., titanic, method="class")
dt_model
prp(dt_model)
dt_predictor = predict(dt_model, titanic, type="class")

confusion_matrix = table(titanic$Survived, dt_predictor)
confusion_matrix
accuracy = sum(diag(confusion_matrix))/sum(confusion_matrix)
accuracy
