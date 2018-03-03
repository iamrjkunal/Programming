#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input{
    int n1;
    int n2;
    int*first_no;
    int*second_no;
    int opcode;
    
};

int max(int a, int b);
int* getin_no(int n);
void reverse_arr(int* a,int count);
void add_nos(int*a,int n1,int*b,int n2);
void sub_nos(int*a,int n1,int*b,int n2);
void mult_nos(int*a,int n1,int*b,int n2);
void div_nos(int*a,int n1,int*b,int n2);
int main() {
	int t,a;
	
	
	scanf("%d",&t);
	
	struct input inp[t];
	for(a=0;a<t;a++){
                        scanf("%d %d",&(inp[a].n1),&(inp[a].n2));
                        inp[a].first_no= getin_no(inp[a].n1);
                        inp[a].second_no= getin_no(inp[a].n2);
                        scanf("%d",&(inp[a].opcode));
	                }
    
	 for(a=0;a<t;a++){
	                    if(inp[a].opcode==1)add_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);                   
	                    else if(inp[a].opcode==2)sub_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    else if(inp[a].opcode==3)mult_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    else if(inp[a].opcode==4)div_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    free(inp[a].first_no);
	                    free(inp[a].second_no);
	                 }
	return 0;
}
int* getin_no(int n)
{   char c[n+1];
    scanf("%s",c);
    int* temp;
    temp=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)temp[i]=c[i]-'0';
    
    return temp;    
}
    
int max(int a, int b)
{
    if(a>b)return a;
    else if(b>a)return b;
    else return a;
} 

void reverse_arr(int* a,int count)
{   int temp, i;
    for (i = 0; i < count/2; i++) {
    temp = a[count-i-1];
    a[count-i-1] = a[i];
    a[i] = temp;      }
    
}

void add_nos(int*a,int n1,int*b,int n2)
{   
    int i,j;
    int l=max(n1,n2)+1;
    int sum[l];
    sum[0]=0;
    int k=l-1;
    int temp=0;

    for(i=n1-1,j=n2-1;i>=0 && j>=0&& k>=0;i--,j--,k--)
        {
            sum[k]=(a[i]+b[j]+temp)%10;
            temp=(a[i]+b[j]+temp)/10;
        }
    while(i>=0&& k>=0)
        {
        sum[k]=(a[i]+temp)%10;
        temp=(a[i]+temp)/10;
        k--;i--;
        }
    while(j>=0&& k>=0)
        {
        sum[k]=(b[j]+temp)%10;
        temp=(b[j]+temp)/10;
        k--;j--;
        }
    sum[0]=temp;
    if(sum[0]==0){ for( i=1;i<l;i++)printf("%d",sum[i]);}
    else {for(i=0;i<l;i++)printf("%d",sum[i]);} 
    printf("\n");
        
}

void sub_nos(int*a,int n1,int*b,int n2)
{   int i,j,k;
    int bor=0;
    int sub[n1];
    for(i=n1-1,j=n2-1,k=n1-1;i>=0&&j>=0&&k>=0;i--,j--,k--)
    {   sub[k]=(a[i]-b[j]+bor+10)%10;
        bor=-1*((a[i]-b[j]+bor)<0);
        

    }
    while(k>=0&&i>=0){ 
                        sub[k]=(a[i]+bor+10)%10;
                        bor=-1*((a[i]+bor)<0);
                        k--;i--;
        
                    }
    if(sub[0]==0){ k=1; while(sub[k]==0){k++;}
                    
                    while(k<n1){printf("%d",sub[k]); k++;}
                    }
    else {for(k=0;k<n1;k++)printf("%d",sub[k]);}
    
    printf("\n");
    
    

}
    
void mult_nos(int*a,int n1,int*b,int n2)
{   
    int i, j, c ;
    int k=0;
    int *mul = (int *) malloc (sizeof(int)*(n1+n2));
    reverse_arr(a,n1);
    
    reverse_arr(b,n2);
    
    int t;
    for (i = 0;i <n1+n2; i++) {
        mul[i] = 0;       }

    for (i = 0; i <n1; i++) 
    {
        c = 0; k = i;
        for (j = 0; j < n2; j++) {
            t = a[i]*b[j];
            t = t + c + mul[k];
            c = t /10;
            mul[k] = t%10;
            k++;                 }
            
        if (c!=0) {
            mul[k] = c;
            k++;
                  }
    }

    
    reverse_arr(mul,n1+n2);
    if(mul[0]==0){ k=1; while(mul[k]==0){k++;}
                    while(k<n1+n2){printf("%d",mul[k]); k++;}
                    }
    else {for(k=0;k<n1+n2;k++)printf("%d",mul[k]);}
    
    
    printf("\n");
    free(mul);
}

void div_nos(int*a,int n1,int*b,int n2)
{ 
    if(n1<n2) printf("%d",0);
    else if(n1=n2 && a[0]<b[0])printf("%d",0);
    
                
                   
  printf("\n");
    
    
    
    
    
    
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input{
    int n1;
    int n2;
    int*first_no;
    int*second_no;
    int opcode;
    
};

int max(int a, int b);
int* getin_no(int n);
void reverse_arr(int* a,int count);
void add_nos(int*a,int n1,int*b,int n2);
void sub_nos(int*a,int n1,int*b,int n2);
void mult_nos(int*a,int n1,int*b,int n2);
void div_nos(int*a,int n1,int*b,int n2);
int main() {
	int t,a;
	
	
	scanf("%d",&t);
	
	struct input inp[t];
	for(a=0;a<t;a++){
                        scanf("%d %d",&(inp[a].n1),&(inp[a].n2));
                        inp[a].first_no= getin_no(inp[a].n1);
                        inp[a].second_no= getin_no(inp[a].n2);
                        scanf("%d",&(inp[a].opcode));
	                }
    
	 for(a=0;a<t;a++){
	                    if(inp[a].opcode==1)add_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);                   
	                    else if(inp[a].opcode==2)sub_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    else if(inp[a].opcode==3)mult_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    else if(inp[a].opcode==4)div_nos(inp[a].first_no,inp[a].n1,inp[a].second_no,inp[a].n2);
	                    free(inp[a].first_no);
	                    free(inp[a].second_no);
	                 }
	return 0;
}
int* getin_no(int n)
{   char c[n+1];
    scanf("%s",c);
    int* temp;
    temp=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)temp[i]=c[i]-'0';
    
    return temp;    
}
    
int max(int a, int b)
{
    if(a>b)return a;
    else if(b>a)return b;
    else return a;
} 

void reverse_arr(int* a,int count)
{   int temp, i;
    for (i = 0; i < count/2; i++) {
    temp = a[count-i-1];
    a[count-i-1] = a[i];
    a[i] = temp;      }
    
}

void add_nos(int*a,int n1,int*b,int n2)
{   
    int i,j;
    int l=max(n1,n2)+1;
    int sum[l];
    sum[0]=0;
    int k=l-1;
    int temp=0;

    for(i=n1-1,j=n2-1;i>=0 && j>=0&& k>=0;i--,j--,k--)
        {
            sum[k]=(a[i]+b[j]+temp)%10;
            temp=(a[i]+b[j]+temp)/10;
        }
    while(i>=0&& k>=0)
        {
        sum[k]=(a[i]+temp)%10;
        temp=(a[i]+temp)/10;
        k--;i--;
        }
    while(j>=0&& k>=0)
        {
        sum[k]=(b[j]+temp)%10;
        temp=(b[j]+temp)/10;
        k--;j--;
        }
    sum[0]=temp;
    if(sum[0]==0){ for( i=1;i<l;i++)printf("%d",sum[i]);}
    else {for(i=0;i<l;i++)printf("%d",sum[i]);} 
    printf("\n");
        
}

void sub_nos(int*a,int n1,int*b,int n2)
{   int i,j,k;
    int bor=0;
    int sub[n1];
    for(i=n1-1,j=n2-1,k=n1-1;i>=0&&j>=0&&k>=0;i--,j--,k--)
    {   sub[k]=(a[i]-b[j]+bor+10)%10;
        bor=-1*((a[i]-b[j]+bor)<0);
        

    }
    while(k>=0&&i>=0){ 
                        sub[k]=(a[i]+bor+10)%10;
                        bor=-1*((a[i]+bor)<0);
                        k--;i--;
        
                    }
    if(sub[0]==0){ k=1; while(sub[k]==0){k++;}
                    
                    while(k<n1){printf("%d",sub[k]); k++;}
                    }
    else {for(k=0;k<n1;k++)printf("%d",sub[k]);}
    
    printf("\n");
    
    

}
    
void mult_nos(int*a,int n1,int*b,int n2)
{   
    int i, j, c ;
    int k=0;
    int *mul = (int *) malloc (sizeof(int)*(n1+n2));
    reverse_arr(a,n1);
    
    reverse_arr(b,n2);
    
    int t;
    for (i = 0;i <n1+n2; i++) {
        mul[i] = 0;       }

    for (i = 0; i <n1; i++) 
    {
        c = 0; k = i;
        for (j = 0; j < n2; j++) {
            t = a[i]*b[j];
            t = t + c + mul[k];
            c = t /10;
            mul[k] = t%10;
            k++;                 }
            
        if (c!=0) {
            mul[k] = c;
            k++;
                  }
    }

    
    reverse_arr(mul,n1+n2);
    if(mul[0]==0){ k=1; while(mul[k]==0){k++;}
                    while(k<n1+n2){printf("%d",mul[k]); k++;}
                    }
    else {for(k=0;k<n1+n2;k++)printf("%d",mul[k]);}
    
    
    printf("\n");
    free(mul);
}

void div_nos(int*a,int n1,int*b,int n2)
{ 
    if(n1<n2) printf("%d",0);
    else if(n1=n2 && a[0]<b[0])printf("%d",0);
    
                
                   
  printf("\n");
    
    
    
    
    
    
}





