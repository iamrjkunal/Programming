#include <bits/stdc++.h>
#include <climits>
using namespace std;
int min_spe(int*,int*);
int n,m;
int main() {
	cin>> n >> m; 
	int adjmat[n][n];
	int i,j;
	int n1,n2,wt;
	int d[n];
	int tree[n];
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        adjmat[i][j]=0;
	    }
	    if(i==0) d[i]=0;
	    else d[i]=INT_MAX;
	    tree[i]=0;
	}
	for(i=0;i<m;i++){
	    cin>> n1 >> n2 >> wt;
        adjmat[n1][n2]=wt;
	    adjmat[n2][n1]=wt; 
	}
	
	for(i=0;i<n;i++){
	    int temp = min_spe(d,tree);
	    tree[temp]=1;
	    for(j=0;j<n;j++){
	        if(adjmat[temp][j]){
	            if(tree[j]==0 && d[j]> adjmat[temp][j]){
	                d[j]=adjmat[temp][j];
	            }
	        }
	    }
	}
	int cost=0;
	for(i=0;i<n;i++){
	    cost = cost + d[i];
	}
	cout<<cost<<endl;
	
	return 0;
}
int min_spe(int* d,int* tree){
    int min = INT_MAX;
    int i,index;
    for(i=0;i<n;i++){
        if(tree[i]==0 && d[i]<=min){
            min=d[i];
            index =i;
        }
    }
    return index;
}