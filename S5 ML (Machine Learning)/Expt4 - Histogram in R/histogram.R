# Load the ggplot2 library
library(ggplot2)

# Load the Titanic dataset (a built-in dataset in R)
data(Titanic)

# Convert the Titanic dataset to a data frame
Titanic_df <- as.data.frame(Titanic)

# Create a histogram using ggplot
ggplot(Titanic_df, aes(x = Freq)) +
  geom_histogram(color = "black", fill = "green", bins = 30)
