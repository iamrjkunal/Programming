import numpy as np
import matplotlib.pyplot as plt

n_train= 10000
n_test = 1000
#step 1

train = np.genfromtxt('train.csv',delimiter=',')
train =  train[1:]

test = np.genfromtxt('train.csv',delimiter=',')
test = test[1:]

x_train = train[:,0]
X_train = np.vstack((np.ones(x_train.size),x_train))
X_train = np.transpose(X_train)
y_train = train[:,1]
#y_train = np.transpose(y_train)

#print (X_train)
#print (y_train)

#step 2
w = np.random.rand(2,1)
#print (w)

#step 3
plt.plot(x_train,y_train)
plt.xlabel('x')
plt.ylabel('y')
plt.show()
xnew = np.transpose(X_train)
wtran1 = np.matmul(np.transpose(w),xnew).ravel()

plt.plot(x_train,wtran1)
plt.show()

#step 4
w_direct = np.matmul(np.matmul(np.linalg.inv(np.matmul(np.transpose(X_train),X_train)),np.transpose(X_train)),y_train)
plt.plot(x_train,y_train)
plt.xlabel('x')
plt.ylabel('y')
plt.show()
wtran2 = np.matmul(np.transpose(w_direct),xnew).ravel()
plt.plot(x_train,wtran2)
plt.show()

#step 5
for nepoch in range(1,3):
    for j in range(1,x_train.size):
        x=np.array([1,train[j][0]])
        y=train[j][1]
        z=0.00000001*(np.matmul(np.transpose(w),x)-y)
        w=w-z*x
        w=w[...,:1]
        if j%100==0:
            x_prim=(np.matmul(np.transpose(w),np.transpose(X_train)).ravel())
            plt.plot(x_prim,x_train)
#step 6
x_prim=(np.matmul(np.transpose(w),np.transpose(X_train)).ravel())
plt.plot(x_prim,x_train)

#step 7
test_data = np.genfromtxt('test.csv', delimiter = ',')
test_data= test_data[1:]
X_test=test_data[:,0]
y_test=test_data[:,1]
X_test=np.transpose(np.vstack((np.ones(X_test.size),X_test)))


y_pred1=np.matmul(X_test,w)
plt.plot(y_pred1,X_test)
err=np.sqrt(((y_test.ravel()-y_pred1.ravel())**2).mean())
print("Error between y_pred1 and y_test:",err)

#print(y_test)

#print(y_pred)

y_pred2=np.matmul(X_test,w_direct)
plt.plot(y_pred2,X_test)
err=np.sqrt(((y_test.ravel()-y_pred2.ravel())**2).mean())
print("Error between y_pred2 and y_test:",err)

plt.plot(y_test,X_test)
plt.show()



