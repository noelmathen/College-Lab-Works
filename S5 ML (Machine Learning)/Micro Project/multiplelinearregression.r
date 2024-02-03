# Load necessary libraries
library(dplyr)
library(tidyr)
library(Metrics)

# Load the data
data <- read.csv("C:\\Users\\online\\Documents\\ML LAB\\Micro Project\\housing.csv")

# Preprocessing
# 4.1: Handling missing values
data <- na.omit(data)
# 4.2: Removing duplicate rows
data <- distinct(data)
# 4.3: Scaling numeric variables
numeric_columns <- c("price", "area", "bedrooms", "bathrooms", "stories", "parking")
data[numeric_columns] <- scale(data[numeric_columns])
# 4.4: Encoding categorical variables
categorical_columns <- c("mainroad", "guestroom", "basement", "hotwaterheating", "airconditioning", "prefarea", "furnishingstatus")
data <- model.matrix(~. - 1, data = data[, c(numeric_columns, categorical_columns)])

# Split the data into training and testing sets
set.seed(123)  # for reproducibility
train_indices <- sample(seq_len(nrow(data)), size = 0.8 * nrow(data))
train_data <- data[train_indices, ]
test_data <- data[-train_indices, ]

# Convert train_data matrix to data frame
train_data <- as.data.frame(train_data)
test_data <- as.data.frame(test_data)

# Fit Multiple Linear Regression model
lm_model <- lm(price ~ ., data = train_data)

# Print the Multiple Linear Regression model summary
summary(lm_model)

# Make predictions on the test set
predictions <- predict(lm_model, newdata = test_data)

# Evaluate regression metrics
cat("Metrics:\n")
cat("MAE:", mae(predictions, test_data$price), "\n")
cat("RMSE:", rmse(predictions, test_data$price), "\n")

plot(lm_model, which = 1)
