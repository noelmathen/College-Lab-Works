#Naive Bayes. I have tried to make the following questions/algorithms similar to this.
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
soybean$Class = factor(soybean$Class)
splitIndex = createDataPartition(soybean$Class, p=0.8, list=FALSE)
train_data = soybean[splitIndex, ] 
train_labels = soybean$Class[splitIndex]
test_data = soybean[-splitIndex, ]
test_labels = soybean$Class[-splitIndex]

naiveBayes_model = naiveBayes(Class~., train_data)
naiveBayes_predictions = predict(naiveBayes_model, test_data)

confusionMatrix(test_labels, naiveBayes_predictions)

#Manual code for finding confusion matrix and accuracy
#confusion_matrix = table(Actual=test_labels, Predicted=naiveBayes_predictions)
#confusion_matrix

#accuracy = sum(diag(confusion_matrix)) / sum(confusion_matrix)
#accuracy


