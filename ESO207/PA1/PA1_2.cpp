#include <stdio.h>
#include <stdlib.h>
struct stack{
    long int data;
    struct stack *next;
};
typedef struct stack STACK;
STACK *front;
STACK *rear;
void enqueue(long int val);
void dequeue();
void is_empty();
int main() {
 
	
    int query,i,j;
    int opcode;
    int testcases;
    scanf("%d",&testcases);
    for(j=1;j<=testcases;j++)
    {   
        front=NULL; // dequeue occurs from front
	    rear=NULL; // enqueue occurs from back
        scanf("%d",&query);
        for(i=1;i<=query;i++)
        {   scanf("%d",&opcode);
            if (opcode==1){long int x;
                        scanf("%ld",&x);
                        enqueue(x);
                        printf("%ld\n",x);
                      }
            else if(opcode==2)dequeue();
                            
                          
            else if(opcode==3)is_empty();
        
        }
    }
	
	
	
	
	
	return 0;
}
void enqueue(long int val)
{
	    STACK *temp;
	    temp=(STACK*)malloc(sizeof(STACK));
	    temp->data=val;
	    temp->next=NULL;
	    if(front==NULL && rear==NULL){
	                                   front=temp;
	                                   rear=temp;
	                                   
	                                 }
	    else {  rear->next=temp;
	            rear=temp;
	        
	           }
}
void dequeue()
{
        STACK *temp=front;
        if(front==NULL){printf("Empty\n");
                        
                        return;
                        }
        if(front==rear){
                        printf("%ld\n",temp->data);
                        front=NULL;
                        rear=NULL;
            
                        }
        else {printf("%ld\n",temp->data);
                front=front->next;
                }
        free(temp);
        
 
    
}
void is_empty()
{   if(front==NULL && rear==NULL)printf("True\n");
    else printf("False\n");
    
    
    
}



