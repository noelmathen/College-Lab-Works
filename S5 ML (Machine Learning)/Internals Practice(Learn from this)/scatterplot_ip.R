library(ggplot2)
ggplot(iris, aes(x=Petal.Length, y=Petal.Width))+
  geom_point(aes(shape=factor(Species)))+
  geom_point(aes(color=factor(Species)))+
  geom_smooth(method = "lm")

#some extra information(not for this code particularly)
data(iris) #load dataset
names(iris) #shows names of features
str(iris) #This line prints the structure of the Iris dataset, showing the data types and first few observations of each variable.
View(iris) #is line opens a data viewer window (if available) to display the entire Iris dataset, allowing you to inspect the data more closely.
