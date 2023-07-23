setwd("\\Users\\noelm\\Desktop\\Saadhangal\\STUDY STEFF\\RSET\\CLASSES\\S2\\RP LAB\\Codes")
dataset=read.csv("tvmarketing.csv", header=T, colClasses = c("character", "character"))
simple.fit = lm(TV~Sales, data=dataset)
summary(simple.fit)
