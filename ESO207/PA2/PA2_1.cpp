#include <iostream>
#include <string>
using namespace std;
struct stack1 {
  int data;
  struct stack1* next;
};
struct stack1* top1=NULL;
void push1(int x);
int pop1();
int isEmpty1();
int main() {
	int test,i;
	int x,y;
	scanf("%d\n",&test);
	string poly;
   for(i=0;i<test;i++){
        int j;
        int k=0;
        int num;
        top1=NULL;
        getline(cin,poly);
        scanf("%d %d\n",&x,&y);
        j=0;
        int op=3;
        while(j<=poly.length()){
            if(j==poly.length() ||poly[j]==' '){ 
                    if(poly[j-1]=='+'){op=3;}         // 1 for divison, 2 for mult, 3 for add, 4 for sub
                    else if (poly[j-1]=='-'){op=4;}
                    else if (poly[j-1]=='*'){op=2;}
                    else if (poly[j-1]=='/'){op=1;}
                    else
                    {string s;
                    s= poly.substr(k,j-k);
                        if(s=="x"||s=="y"||s=="xy"||s=="yx"){
                            num=1;
                        }else{
                             num= stoi(s); 
                        }
                    if(poly[j-1]=='x' && poly[j-2]=='y'){num=num*x*y;}
                    else if(poly[j-1]=='y' && poly[j-2]=='x'){num=num*y*x;}
                    else if(poly[j-1]=='x'){num=num*x;}
                    else if(poly[j-1]=='y'){num=num*y;}
                    if(op==1 || op==2){
                        if(op==1){num=pop1()/num; push1(num);}
                        else{num=pop1()*num; push1(num);}
                                    }
                    else if (op==4){ num= -1*num; push1(num);}
                    else{
                        push1(num);
                    }
                    }
                    k=j+1;
            }
         j++;   
        }
      int output=0;  
     while(isEmpty1()==0){ 
                        output=output + pop1();
                    }   
   cout<< output <<endl;
   }    
	return 0;
}
void push1(int x){
    struct stack1* temp=(struct stack1*)malloc(sizeof(struct stack1));
    temp->data=x;
    temp->next=top1;
    top1=temp;
}
int pop1(){
    int a;
    struct stack1* temp;
    if(top1==NULL){return 0;
                }
    temp=top1;
    top1=top1->next;
    a=temp->data;
    free(temp);
    return a;
}
int isEmpty1(){
    if(top1==NULL)return 1;
    else return 0;
}
