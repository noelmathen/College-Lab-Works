#install.packages("gbm")
library(gbm)

data(iris)
set.seed(123)

boosted_model <- gbm(Species ~ ., data = iris, distribution = "multinomial",
                     n.trees = 100, interaction.depth = 3, shrinkage = 0.1)
predictions <- predict(boosted_model, newdata = iris, n.trees = 100, type = "response")
predicted_labels <- apply(predictions, 1, which.max)

confusion_matrix <- table(predicted_labels, iris$Species)
confusion_matrix
accuracy <- sum(diag(confusion_matrix))/sum(confusion_matrix)
accuracy
