library(ggplot2)
data(Titanic)
Titanic_df <- as.data.frame(Titanic)
ggplot(Titanic_df, aes(x = Freq)) + geom_histogram(color = "black", fill = "green", bins = 30)

