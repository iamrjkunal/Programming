#include <bits/stdc++.h>
using namespace std;
void DFS(int dfs_value,int rem_value, vector< int > *adj,int* visit);
stack <int> dfs;
int main() {
	int n,m;
	cin >> n >> m;
	vector< int > adj[n];
	vector<int> bad_island;
	int visit [n];
	int i,j; // all iterator variables
	int n1,n2;
	for(i=0;i<n;i++){
	    visit[i]=0;
	}
	for(i=0;i<m;i++){
	    cin >> n1 >> n2;
	    adj[n1].push_back(n2);
	    adj[n2].push_back(n1);
	}
	for(i=0;i<n;i++){
	    DFS((i+1)%n,i,adj,visit);
	    int count =0;
	    for(j=0;j<n;j++){
	        if(visit[j] == 0 && j!=i){
	            count++;
	            if(count ==1)
	                bad_island.push_back(i);
	            
	        }
	        else{
	            visit[j]=0;
	        }
	    }
	}
	sort(bad_island.begin(),bad_island.end());
	for(i=0;i<bad_island.size();i++){
	    cout <<bad_island[i]<<endl;
	}
	return 0;
}

void DFS(int dfs_value,int rem_value,vector< int > *adj,int* visit){
    dfs.push(dfs_value);
    while(!dfs.empty()){
        int temp = dfs.top();
        dfs.pop();
        if(visit[temp]==0){
            visit[temp]=1;
        }
        for(int j=0;j<adj[temp].size();j++){
            if( adj[temp][j]!= rem_value){
                if(visit[adj[temp][j]]==0 ){
                    dfs.push(adj[temp][j]);
                }    
            }
        }
    }
}