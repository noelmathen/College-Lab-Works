library(e1071)
library(caret)
library(class)
data("iris")
set.seed(123)

iris$Species = factor(iris$Species)
splitIndex = createDataPartition(iris$Species, p=0.8, list=FALSE)
train_data = iris[splitIndex, -5]
train_label = iris$Species[splitIndex]
test_data = iris[-splitIndex, -5]
test_label = iris$Species[-splitIndex]

knn_model = knn(train_data, test_data, train_label, k=1)

confusion_matrix = table(knn_model,test_label)
confusion_matrix
