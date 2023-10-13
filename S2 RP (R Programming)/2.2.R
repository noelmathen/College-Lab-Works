diff=threed[1,2,1]-threed[1,1,1]
print("The difference in the stock price of Apple is:")
print(diff)
diff_price_num=as.integer(diff)
percent_diff=(diff-diff_price_num)*100
cat("\nThe difference percentage is :",percent_diff)
cat("\n the stock price of apple in 2018 and 2019 are:",threed[1,2,1],"and",threed[1,1,1])
