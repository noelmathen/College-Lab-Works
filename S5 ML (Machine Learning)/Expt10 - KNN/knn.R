library(class)
data(iris)

# Split data into training and testing sets
set.seed(123)  # Set seed for reproducibility
train_index <- sample(1:nrow(iris), size=75)
train_data <- iris[train_index,]
test_data <- iris[-train_index,]

# Perform KNN classification
predicted_species <- knn(train_data[, -5], test_data[, -5], train_data$Species, k=1)

# Evaluate accuracy
confusion_matrix <- table(predicted_species, test_data$Species)
accuracy <- sum(diag(confusion_matrix)) / nrow(test_data)

print(confusion_matrix)
print(paste("Accuracy:",accuracy))

confusionMatrix(knn_model, test_labels)
