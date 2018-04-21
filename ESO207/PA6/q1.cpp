#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int>& a,int value,vector<int>* adj, int* visit);
vector<int> SC(vector<int>& a,vector<int>* rev_adj, int* visit);
int find_sc(int value);
int min_fn(vector<int>& a);
stack<int> f_time;
vector< vector<int> > sc;
vector < int> temp;
int main(){
	// taking input
	int i,n,c;
	cin>> n;
	int visit[n];
	vector<int> adj[n] ;
    vector<int> rev_adj[n];
	for(i=0;i<n;i++){
	    int temp1;
	    cin>> temp1;
	    while(temp1 !=-1){
	        adj[i].push_back(temp1);
	        rev_adj[temp1].push_back(i);
	        cin>> temp1;
	    }
	    adj[i].push_back(-1);
	}
	/* 
	for(i=0;i<n;i++){
	    for(int j=0;j<adj[i].size();j++){
	        cout<< adj[i][j]<<" ";
	    }
	    cout<< endl;
	} 
	*/
	
	// implementing dfs
	for(i=0;i<n;i++){
	    visit[i]=0;
	}
	for(i=0;i<n;i++){
	    if(visit[i]==0){
	       DFS(adj[i],i,adj,visit); 
	    }
	}
	
	
	// getting strongly connected component
	for(i=0;i<n;i++){
	    visit[i]=0;
	}
	while (!f_time.empty()){
	    c= f_time.top();
	    if(visit[c]==1){
	        f_time.pop();
	        continue;
	    }
	    f_time.pop();
	    visit[c]=1;
	    temp.push_back(c);
	    SC(rev_adj[c],rev_adj,visit);
	    sc.push_back(temp);
	    temp.clear();
	}
	
	// MAKE GRAPH
	int size =sc.size();
	    int adjmat[n][n];
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adjmat[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(int j=0;j<adj[i].size()-1;j++){
            adjmat[i][adj[i][j]]=1;
        }
    }
    int order_id[size];
    int label_sc[size];
    for(int i=0;i<size;i++){
        order_id[i]=min_fn(sc[i]);
    }
    for(int i=0;i<size;i++){
        label_sc[i]=order_id[i];
    }
    sort(order_id,order_id+size);
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(order_id[i]==label_sc[j]){
                label_sc[j]=count;
                count++;
            }
        }
    }
    int n1,n2;
    /*
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    vector<int> output[size];
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjmat[i][j]==1){
                n1=find_sc(i);
                n2=find_sc(j);
                if(n1!=n2)
                    output[label_sc[n1]].push_back(label_sc[n2]);
            }
        }
    }
    cout<< sc.size()<<endl;
    for(int i=0;i<size;i++){
        sort(output[i].begin(),output[i].end());
    }
    for(i=0;i<size;i++) output[i].push_back(-1);
	for( int m=0;m<size;m++){
	    for(int h=0; h<output[m].size();h++){
	        cout << output[m][h]<< " ";
	    }
	    cout << "\n";
	}
  	/*
  	for( int m=0;m<sc.size();m++){
	    for(int h=0; h<sc[m].size();h++){
	        cout << sc[m][h]<< " ";
	    }
	    cout << "\n";
	}
    cout<<endl;
    */
    /*
    for(int m=0;m<size;m++)
          cout << label_sc[m]<<endl;
	*/
	return 0;
}
void DFS(vector<int>& a,int value,vector<int>* adj, int* visit){
    int k;
	for(k=0;k<a.size();k++){
	    if(a[k]!= -1){
	       	if(visit[a[k]]==0){
	        visit[a[k]]=1;
	        DFS(adj[a[k]],a[k],adj,visit);
	        }
	    }
	}
	f_time.push(value);
}
vector<int> SC(vector<int>& a,vector<int>* rev_adj, int* visit){
    int k;
	for(k=0;k<a.size();k++){
	    if(visit[a[k]]==0){
	        visit[a[k]]=1;
	        temp.push_back(a[k]);
	        SC(rev_adj[a[k]],rev_adj,visit);
	    }
	}
	return temp;
}
int find_sc(int value){
    for(int i=0;i<sc.size();i++){
        for(int j=0;j<sc[i].size();j++){
            if(sc[i][j]==value){
                return i;
            }
        }
    }
}
int min_fn(vector<int>& a){
    int min = a[0];
	for(int j =1; j< a.size();j++){
	    if(a[j]<min)
	        min = a[j];
	}
	return min;
}


