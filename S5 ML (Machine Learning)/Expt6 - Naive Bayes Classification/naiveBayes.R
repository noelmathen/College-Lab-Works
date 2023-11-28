#importing dataset
library(mlbench)
library(caret)
library(e1071)
dataset <- read.csv("C:\\Users\\Student\\Documents\\ML LAB\\Expt5\\Soybean.csv")
head(dataset, n = 50)

#Preprocessing
sum(is.na(dataset))
soybean <- na.omit(dataset)
soybean
preproc <- preProcess(soybean[, -1], method = c("center", "scale"))
preproc
soybean[, -1] <- predict(preproc, soybean[, -1])
set.seed(123)  # For reproducibility
splitIndex <- createDataPartition(soybean$Class, p = 0.8, list = FALSE)
training_data <- soybean[splitIndex, ]
testing_data <- soybean[-splitIndex, ]

# Fitting Naive Bayes Model to training dataset
set.seed(120)  # Setting Seed
classifier_soybean <- naiveBayes(Class ~ ., data = training_data)
classifier_soybean

# Predicting on test data
y_pred_soybean <- predict(classifier_soybean, newdata = testing_data)

# Confusion Matrix
cm_soybean <- table(testing_data$Class, y_pred_soybean)
cm_soybean

# Model Evaluation
confusionMatrix(cm_soybean)