#KNN
#install.packages("class")
#install.packages("caret")

library(caret)

data(iris)

set.seed(123)
splitIndex <- createDataPartition(iris$Species, p = 0.8, list = FALSE)
train_data <- iris[splitIndex, -5]
train_labels <- iris$Species[splitIndex]
test_data <- iris[-splitIndex, -5]
test_labels <- iris$Species[-splitIndex]

knn_model <- knn(train_data, test_data, train_labels, k = 1)

confusionMatrix(test_labels, knn_model)

#confusion_matrix <- table(Actual=test_labels, Predicted=knn_model)
#confusion_matrix

#accuracy <- sum(diag(confusion_matrix)) / nrow(test_data)
#accuracy

