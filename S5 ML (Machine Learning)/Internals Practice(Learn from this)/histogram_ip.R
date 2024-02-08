iris_df = as.data.frame(iris)
ggplot(iris, aes(x = Sepal.Length)) +
  geom_histogram(color="red", fill="black", bins=20,)