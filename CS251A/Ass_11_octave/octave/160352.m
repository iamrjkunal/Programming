#step 1
data= csvread("train.csv");
n_data= data;
n_data([1],:)=[];
x_train= data(2:end, 1);
y_train= data(2:end, 2);
new_x_train= [ones(size(x_train, 1), 1) x_train];

#step 2
w= rand(2,1);

#step 3
figure(1)
scatter(x_train,y_train,'m');
hold on;
x_bar = new_x_train.';
plot(x_train, (w.'*x_bar).','g'); 

#step 4
w_direct= inv(new_x_train.'*new_x_train)*new_x_train.'*y_train;
figure(2)
scatter(x_train,y_train,'m');
hold on;
plot(x_train, w_direct.'*x_bar,'b');

#step 5
n_train= 10000;
eta= 0.00000001;
figure(3)
for i = 1:2
  for j = 1:n_train
    y = n_data(j,2);
    x = n_data(j,1);
    x = [ones(size(x, 1), 1) x];
    x = x.';
    w= w - eta*(w.'*x - y)*x;
    if (mod(j,100) == 0)
      plot(x_train, (w.'*x_bar).','g');
      hold on;
    endif
  endfor
endfor

#step 6
figure(4)
plot(x_train, (w.'*x_bar).','g');

#step 7
test_data= csvread("test.csv");
x_test= test_data(2:end, 1);
y_test= test_data(2:end, 2);
new_x_test= [ones(size(x_test, 1), 1) x_test];
y_pred1= new_x_test*w;
y_error1= y_test - y_pred1;
y_error1= y_error1.^2;
y_error1 = sqrt(mean(y_error1))

y_pred2= new_x_test*w_direct;
y_error2= y_test - y_pred2;
y_error2= y_error2.^2;
y_error2 = sqrt(mean(y_error2))

fgetl(stdin);





