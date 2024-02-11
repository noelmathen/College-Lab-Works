library(caret)
library(e1071)

dataset = read.csv("Soybean.csv")
sum(is.na(dataset))
soybean = na.omit(dataset)
sum(is.na(soybean))

preproc = preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] = predict(preproc, soybean[, -1])

soybean$Class = factor(soybean$Class)
splitIndex = createDataPartition(soybean$Class, p=0.8, list=FALSE)
train_data = soybean[splitIndex, ]
train_label = soybean$Class[splitIndex]
test_data = soybean[-splitIndex, ]
test_label = soybean$Class[-splitIndex]

nb_model = naiveBayes(Class~., train_data)
nb_predictor = predict(nb_model, test_data)

confusionMatrix(test_label, nb_predictor)
