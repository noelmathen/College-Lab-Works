library(randomForest)
library(e1071)
library(caret)

dataset = read.csv("Soybean.csv")
sum(is.na(dataset))
soybean = na.omit(dataset)

preproc = preProcess(soybean[, -1], method=c("center", "scale"))
soybean[, -1] = predict(preproc, soybean[, -1])

soybean$Class = factor(soybean$Class)
splitIndex = createDataPartition(soybean$Class, p=0.8, list=FALSE)
train_data = soybean[splitIndex, ]
train_label = soybean$Class[splitIndex]
test_data = soybean[-splitIndex, ]
test_label = soybean$Class[-splitIndex]

rf_model = train(Class~., train_data, metho="rf")
rf_predictor = predict(rf_model, test_data)

confusionMatrix(rf_predictor, test_label)
