library(rpart)
library(rpart.plot)

titanic = read.csv('titanic.csv')
titanic = titanic[, c("Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Survived")]

sum(is.na(titanic))
titanic = na.omit(titanic)

titanic$Sex = as.factor(titanic$Sex)
decisionTree_model = rpart(Survived~., titanic, method = "class")
print(decisionTree_model)
prp(decisionTree_model)
decisionTree_predictor = predict(decisionTree_model, titanic, type="class")

confusion_matrix = table(titanic$Survived, decisionTree_predictor)
confusion_matrix