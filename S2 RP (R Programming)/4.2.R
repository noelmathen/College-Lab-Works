library(ggplot2)
ggplot(diamonds, aes(x=price))+geom_histogram(aes(color="red", fill="green"))
