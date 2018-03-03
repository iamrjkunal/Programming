#include <stdio.h>
#include <stdlib.h>
struct stack{
    long int data;
    struct stack *next;
};
typedef struct stack STACK;

void enqueue(long int val,STACK **front,STACK **rear);
void dequeue(STACK **front,STACK **rear);
void is_empty(STACK *front,STACK *rear);
int main() {
 
	
    int query,i,j,k,n;
    int opcode;
    int testcases;
    scanf("%d",&testcases);
    for(j=1;j<=testcases;j++)
    {   

        scanf("%d %d",&n,&query);
        
        STACK *front[n];  // dequeue occurs from front
        STACK *rear[n];   // enqueue occurs from back
        for(k=0;k<n;k++){
                            front[k]=NULL;
                            rear[k]=NULL;
                        }
        for(i=1;i<=query;i++)
        {   
            
            scanf("%d",&opcode);
            if (opcode==1){ long int a;
                            scanf("%ld %d",&a,&k);
                            enqueue(a,&front[k-1],&rear[k-1]);
                            printf("%ld\n",a);
                          }
            else if(opcode==2){ scanf("%d",&k);
                                dequeue(&front[k-1],&rear[k-1]);
                                }
                          
            else if(opcode==3){ scanf("%d",&k);
                                is_empty(front[k-1],rear[k-1]);
                                }
        }
    }
	
	
	
	
	
	return 0;
}
void enqueue(long int val,STACK **front,STACK **rear)
{
	    STACK *temp;
	    temp=(STACK*)malloc(sizeof(STACK));
	    temp->data=val;
	    
	    temp->next=NULL;
	    if(*front==NULL && *rear==NULL){
	                                   *front=temp;
	                                   *rear=temp;
	                                   
	                                 }
	    else {  (*rear)->next=temp;
	            *rear=temp;
	        
	           }
}
void dequeue(STACK **front,STACK **rear)
{
        STACK *temp=*front;
        if(*front==NULL){printf("Empty\n");
                        
                        return;
                        }
        if(*front==*rear){
                        printf("%ld\n",temp->data);
                        *front=NULL;
                        *rear=NULL;
            
                        }
        else {printf("%ld\n",temp->data);
                *front=(*front)->next;
                }
        free(temp);
        
 
    
}
void is_empty(STACK *front,STACK *rear)
{   if(front==NULL && rear==NULL)printf("True\n");
    else printf("False\n");
    
    
    
}



