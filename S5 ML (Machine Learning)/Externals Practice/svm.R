library(caret)
data(iris)

set.seed(123)
splitIndex <- createDataPartition(iris$Species, p = 0.8, list = FALSE)
train_data <- iris[splitIndex, -5]  
train_labels <- iris$Species[splitIndex]
test_data <- iris[-splitIndex, -5] 
test_labels <- iris$Species[-splitIndex]

svm_model = svm(train_data, train_label, kernel="radial", cost=1)
svm_predictor = predict(svm_model, test_data)

confusionMatrix(svm_predictor, test_label)
