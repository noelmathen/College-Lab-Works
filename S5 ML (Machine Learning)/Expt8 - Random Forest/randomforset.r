library(mlbench)
library(caret)
library(randomForest)

dataset <- read.csv("Soybean.csv")
dataset

sum(is.na(dataset))
soybean <- na.omit(dataset)
preproc <- preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] <- predict(preproc, soybean[, -1])
set.seed(123)  # For reproducibility
soybean$Class = factor(soybean$Class)
splitIndex <- createDataPartition(soybean$Class, p = 0.8, list = FALSE)
training_data <- soybean[splitIndex, ]
testing_data <- soybean[-splitIndex, ]

# Train a Random Forest classifier
model <- train(Class ~ ., data = training_data, method = "rf")

# Make predictions on the testing data
predictions <- predict(model, newdata = testing_data)

# Evaluate the model's performance
confusionMatrix(predictions, testing_data$Class)

