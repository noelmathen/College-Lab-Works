library(ggplot2)
ggplot(iris,aes(x=Petal.Length,y=Petal.Width))+
  geom_point(aes(shape=factor(Species)))+
  geom_point(aes(color=factor(Species)))+
  geom_smooth(method="lm")


