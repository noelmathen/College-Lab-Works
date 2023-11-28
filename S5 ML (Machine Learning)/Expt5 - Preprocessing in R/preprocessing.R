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

training_data
testing_data