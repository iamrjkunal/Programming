#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int n,op;
	cin>> n >> op;
	string oper;
	int num_nodes;
	int i,j,k,l;
	vector<int> node[n+1] ;
	int temp;
	int temp1,temp2;
	for(i=0;i<op;i++){
	    cin>> oper;
	    if(oper=="addnode"){
	        cin>> temp;
	        node[temp].push_back(temp);
	    }
	    else if(oper=="addlink"){
	        cin>> temp1 >> temp2;
	        node[temp1].push_back(temp2);
	        node[temp2].push_back(temp1);

	    }
	    else if(oper=="delnode"){
	        cin>> temp;

            for(j=1;j<n+1;j++){
                for(k=1;k<node[j].size();k++){
                    if(node[j][k]==node[temp][0]){
                        node[j].erase(node[j].begin() +k);
                        break;
                    }
                }
            }

	        node[temp].clear(); //erased node
	    }
	    else if(oper=="remlink"){
	        cin>> temp1 >> temp2;
	        for(j=1;j<node[temp1].size();j++){
	            if(node[temp1][j]==temp2){
	                node[temp1].erase(node[temp1].begin()+j);
	                break;
	            }
	        }
	       for(j=1;j<node[temp2].size();j++){
	            if(node[temp2][j]==temp1){
	                node[temp2].erase(node[temp2].begin()+j);
	                break;
	            }
	        }
	    }
	}
	cin>> num_nodes;
	int neigh;
	for(i=0; i<num_nodes;i++){
	    cin>> neigh;
	    if(node[neigh].empty()) cout<<"not in network"<<endl;
	    else if(node[neigh].size()==1) cout <<"no connections"<<endl;
	    else {
	        for(j=1;j<node[neigh].size();j++){
	            cout<<node[neigh][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
