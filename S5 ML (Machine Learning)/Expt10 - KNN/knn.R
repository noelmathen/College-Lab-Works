install.packages("class")
library(class)
data(iris)
set.seed(123)  # For reproducibility
sample_index <- sample(1:nrow(iris), 0.7 * nrow(iris))
train_data <- iris[sample_index, ]
test_data <- iris[-sample_index, ]
# Define the number of neighbors (k)
k <- 3

# Perform k-NN classification
predicted_species <- knn(train_data[, 1:4], test_data[, 1:4], train_data$Species, k)
# Compute accuracy
accuracy <- mean(predicted_species == test_data$Species)
cat("Accuracy:", accuracy)
