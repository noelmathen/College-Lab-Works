library(ggplot2)
ggplot(iris, aes(x=Sepal.Length))+
  geom_histogram(color="black", fill="yellow", bins=20, )



library(ggplot2)
data(Titanic)
data("Titanic")
df = as.data.frame(Titanic)
ggplot(df, aes(x=Freq))+
  geom_histogram(color= "black", fill="blue", bins=30)
