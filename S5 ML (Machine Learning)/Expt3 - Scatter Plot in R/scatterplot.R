# Load the ggplot2 library
library(ggplot2)

# Create a scatter plot using ggplot
ggplot(iris, aes(x = Petal.Length, y = Petal.Width)) +
  # Add points to the plot, using the 'Species' variable for shape
  geom_point(aes(shape = factor(Species))) +
  # Add points to the plot, using the 'Species' variable for color
  geom_point(aes(color = factor(Species))) +
  # Add a linear regression line to the plot
  geom_smooth(method = "lm")
