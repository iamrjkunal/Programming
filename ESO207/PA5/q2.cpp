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
	int visit[n];
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        adjmat[i][j]=0;
	    }
	    if(i==0) d[i]=0;
	    else d[i]=INT_MAX;
	    visit[i]=0;
	}
	for(i=0;i<m;i++){
	    cin>> n1 >> n2 >> wt;
        adjmat[n1][n2]=wt;
	    adjmat[n2][n1]=wt; 
	}
	
	for(i=0;i<n;i++){
	    int temp = min_spe(d,visit);
	    visit[temp]=1;
	    for(j=0;j<n;j++){
	        if(adjmat[temp][j]){
	            if(visit[j]==0 && d[j]>d[temp]+ adjmat[temp][j]){
	                d[j]=d[temp]+ adjmat[temp][j];
	            }
	        }
	    }
	}
	cout<<d[n-1]<<endl;
	
	return 0;
}
int min_spe(int* d,int* visit){
    int min = INT_MAX;
    int i,index;
    for(i=0;i<n;i++){
        if(visit[i]==0 && d[i]<=min){
            min=d[i];
            index =i;
        }
    }
    return index;
}
