#include <bits/stdc++.h>
#include <vector>
using namespace std;
void treetransversal(vector< vector<int> > &tree,int x);

int main() {
	int i,j, test,vertices;
	cin >> test;
	for(j=0;j<test;j++){
	  cin>> vertices;  
	
	vector< vector<int> > tree(vertices) ;
	for(i=0;i<vertices-1;i++){
	    int p,c;
	    cin>>p>>c;
	    
	    
	    tree[p-1].push_back(c-1);
	}
	
	for(i=0;i<vertices;i++){
	sort(tree[i].begin(), tree[i].end());
	}
	treetransversal(tree,0);
	
	}
	return 0;
}
void treetransversal(vector< vector<int> > &tree,int x){
    int i;
    
    for(i=0;i<(tree[x].size())/2;i++){ 
    treetransversal( tree,tree[x][i]);
    }
    cout<< x+1<<" ";
    
    for(i=(tree[x].size())/2;i<tree[x].size();i++){
    treetransversal(tree,tree[x][i]);
    }
    
    
    
}






