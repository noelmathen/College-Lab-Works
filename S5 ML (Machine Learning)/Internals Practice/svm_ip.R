#SVM
#install.packages("e1071")
#install.packages("caret")

library(e1071)
library(caret)

data(iris)

set.seed(123)
splitIndex <- createDataPartition(iris$Species, p = 0.8, list = FALSE)
train_data <- iris[splitIndex, -5]  
train_labels <- iris$Species[splitIndex]
test_data <- iris[-splitIndex, -5] 
test_labels <- iris$Species[-splitIndex]

svm_model <- svm(train_data, train_labels, kernel = "radial", cost = 1)
svm_predictions <- predict(svm_model, test_data)

confusion_matrix <- table(Actual = test_labels, Predicted = svm_predictions)
confusion_matrix

accuracy <- sum(diag(confusion_matrix)) / sum(confusion_matrix)
accuracy

confusionMatrix(svm_predictions,test_labels)
