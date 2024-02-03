install.packages("mlbench")
install.packages("caret")
install.packages("ggplot2")

library(mlbench)
library(ggplot2)
library(caret)

soybean_df <- read.csv("D:\\S5\\ML\\exp5\\Soybean.csv")
nrow(soybean_df)
head(soybean_df)


#number of missing value cells
sum(is.na(soybean_df))
#omit rows with NA value cells
soybean <- na.omit(soybean_df)
nrow(soybean)
head(soybean)
soybean

#normalization or scaling
preproc <- preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] <- predict(preproc, soybean[, -1])
set.seed(123)  # For reproducibility

#split 80% to training and 20% to test data
splitIndex <- createDataPartition(soybean$Class, p = 0.8, list = FALSE)
training_data <- soybean[splitIndex, ]
nrow(training_data)
head(training_data)
training_data
testing_data <- soybean[-splitIndex, ]
nrow(testing_data)
head(testing_data)
testing_data