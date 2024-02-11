#Common Preprocessing Code
#install.packages("e1071")
#install.packages("caret")

library(e1071)
library(caret)

dataset = read.csv("Soybean.csv")

sum(is.na(dataset))
soybean=na.omit(dataset)
preproc = preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] = predict(preproc, soybean[, -1])

set.seed(123)
soybean$Class = as.numeric(factor(soybean$Class))
soybean
splitIndex = createDataPartition(soybean$Class, p=0.8, list=FALSE)
train_data = soybean[splitIndex, ] 
train_labels = soybean$Class[splitIndex]
test_data = soybean[-splitIndex, ]
test_labels = soybean$Class[-splitIndex]
