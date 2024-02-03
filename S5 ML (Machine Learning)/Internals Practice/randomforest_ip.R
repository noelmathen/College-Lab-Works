#Random Forest
#install.packages("e1071")
#install.packages("caret")
#install.packages("randomForest)

library(e1071)
library(caret)
library(randomForest)

dataset = read.csv("Soybean.csv")

sum(is.na(dataset))
soybean=na.omit(dataset)
preproc = preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] = predict(preproc, soybean[, -1])

set.seed(123)
soybean$Class = factor(soybean$Class)
splitIndex = createDataPartition(soybean$Class, p=0.8, list=FALSE)
train_data = soybean[splitIndex, ] 
train_labels = soybean$Class[splitIndex]
test_data = soybean[-splitIndex, ]
test_labels = soybean$Class[-splitIndex]

randomForest_model = train(Class~., train_data, method="rf")
randomForest_predictions = predict(randomForest_model, test_data)

confusion_matrix = table(Actual=test_labels, Predicted=randomForest_predictions)
confusion_matrix

accuracy = sum(diag(confusion_matrix)) / sum(confusion_matrix)
accuracy

confusionMatrix(test_labels, randomForest_predictions)
