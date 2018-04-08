#step 1
num_samples <- 50000
data <- rexp(num_samples, 0.2)
X <- data.frame(iter = seq(1, num_samples , 1), X = sort(data))
plot(X)


#step 2
Y <- split(data, ceiling(seq_along(data)/100))


#step 3
for(j in 1:5){
  pdata <- rep(0, 100);
  for(i in 1:100){
    val=round(Y[[j]][i], 0);
    if (val <=100){
      pdata[val] = pdata[val] + 1/ 100; 
    }
    
  }
  xcols <- c(0:99)
  str(pdata)
  str(xcols)
  plot(xcols, pdata, "l", xlab="X", ylab="f(X)")
  
  cdata <- rep(0, 100)
  cdata[1] <- pdata[1]
  for(i in 2:100){
    cdata[i] = cdata[i-1] + pdata[i]
  }
  
  plot(xcols, cdata, "o", col="blue", xlab="X", ylab="F(X)");
  
}

mean1 <- lapply(Y,mean)
sd1 <- lapply(Y,sd)
for(k in 1:5){
  cat("mean of Y",k,"is ",mean1[[k]],"\n")
  cat("sd of Y",k,"is ",sd1[[k]],"\n")
} 



#step 4
Z <- unlist(mean1,use.names=FALSE)
tab <- table(round(Z))

str(tab)
plot(tab, "h", xlab="Value", ylab="Frequency")

pdata <- rep(0, 100);
for(i in 1:500){
  val=round(Z[i], 0);
  if(val<=100){
    pdata[val] = pdata[val] + 1/500;
  }
   
}
xcols <- c(0:99 )
str(pdata)
str(xcols)
plot(xcols, pdata, "l", xlab="X", ylab="f(X)")

cdata <- rep(0, 100)
cdata[1] <- pdata[1]
for(i in 2:100){
  cdata[i] = cdata[i-1] + pdata[i]
}

plot(xcols, cdata, "o", col="blue", xlab="X", ylab="F(X)")



#step 5
meanZ <- mean(Z)
sdZ <- sd(Z)
cat("mean of Z","is ",meanZ,"\n")
cat("sd of Z","is ",sdZ,"\n")


#step 6
meansample <- mean(data)
sdsample <- sd(data)
cat("mean of sample","is ",meansample,"\n")
cat("sd of sample","is",sdsample,"\n")

