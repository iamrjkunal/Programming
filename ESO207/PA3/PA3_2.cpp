#include <bits/stdc++.h>
using namespace std;
struct bst{
    string data;
    struct bst* left;
    struct bst* right;
    int count_left=0;
} typedef bst;
bst* new_node(string data);
bst* learn(bst* root,string data);
bst* forget(bst* root,string data);
bst* find_min(bst* root,string data);
int rankfind(bst* root,string data);
int main() {
	int i,q;
	cin>> q;
	bst* root=NULL;
	for(i=0;i<q;i++){
	    string op,val;
	    cin>> op;
	    cin>> val;
	    if(op=="learn"){
	        root=learn(root,val);
	    }
	    else if(op=="forget"){
	        cout<<rankfind(root,val)<< endl;
	        root=forget(root,val);
	        
	    }
	    else if(op=="findrank"){
	        cout<<rankfind(root,val)<< endl;
	    }
	}


	return 0;
}

bst* new_node(string data){
    bst* node= new bst;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
bst* learn(bst* root,string data){
    if(root==NULL){ root=new_node(data);}
    else if(data < root->data){
        root->left=learn(root->left,data);
        root->count_left++;
    }
    else {
        root->right=learn(root->right,data);
    }
    return root;
}
bst* find_min(bst* root){
    bst* prev_root = root;
    while(root!=NULL){
        prev_root= root;
        root=root->left;
    }
    return prev_root;
}
bst* forget(bst* root,string data){
    if(root==NULL)return root;
    else if (data< root->data) {
        root->left=forget(root->left,data);
        root->count_left--;
    }
    else if (data> root->data) root->right=forget(root->right,data);
    else{
            if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
            }
            else if(root->left==NULL){
                bst* temp=root;
                root=root->right;
                free(temp);
            }
            else if(root->right==NULL){
                bst* temp=root;
                root=root->left;
                free(temp);
            }
            else{
                bst* temp= find_min(root->right);
                root->data=temp->data;
                root->right= forget(root->right,temp->data);
            }
    }
    return root;
}
int rankfind(bst* root,string data){
    int rank=0;
    while(root!=NULL){
        if(data<root->data) root=root->left;
        else if(data>root->data){
            rank=rank + root->count_left + 1;
            root=root->right;
        }
        else{
            return (rank + root->count_left +1) ;
        }
            
    }
}





