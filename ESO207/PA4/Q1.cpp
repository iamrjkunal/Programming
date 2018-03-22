#include <bits/stdc++.h>
using namespace std;
struct bst{
    string data;
    struct bst* left;
    struct bst* right;
    int lc;
    int rc;
    int ht;
} typedef bst;
/* rotation starts*/
bst* rotateleft(bst* x);
bst* rotateright(bst* x);
bst* ll_rotation(bst* t);
bst* rr_rotation(bst* t);
bst* lr_rotation(bst* t);
bst* rl_rotation(bst* t);
int height(bst* t);
int bf(bst* t);
bst* fixbf_learn(bst* root, string data);
bst* fixbf_forget(bst* root);
//

bst* new_node(string data);
bst* learn(bst* root,string data);
bst* forget(bst* root,string data);
bst* find_min(bst* root,string data);
int rankfind(bst* root,string data);
//
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
//
//
bst* new_node(string data){
    bst* node= new bst;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->lc=0;
    node->rc=0;
    node->ht = 1;
    return node;
}
bst* learn(bst* root,string data){
    if(root==NULL){ 
        root=new_node(data);
    }
    else if(data < root->data){
        root->left=learn(root->left,data);
        root->lc++;
        root = fixbf_learn(root, data);
        
    }
    else{
        
        root->right=learn(root->right,data);
        root->rc++;
        root = fixbf_learn(root, data);
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
        root->lc--;
        root = fixbf_forget(root);
    }
    else if (data> root->data){ 
        root->right=forget(root->right,data);
        root->rc--;
        root = fixbf_forget(root);
    }
    else{
            if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            }
            else if(root->left==NULL){
                bst* temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL){
                bst* temp=root;
                root=root->left;
                delete temp;
            }
            else{
                bst* temp= find_min(root->right);
                root->data=temp->data;
                root->right= forget(root->right,temp->data);
                root->rc--;
            }
    }
    return root;
}
int rankfind(bst* root,string data){
    int rank=0;
    while(root!=NULL){
        if(data < root->data) root=root->left;
        else if(data > root->data){
            rank=rank + root->lc +1;
            root=root->right;
        }
        else{
            return (rank + root->lc +1 ) ;
        }
    }
}
bst* rotateleft(bst* x){
    bst* y;
    y= x->right;
    //updating childs
    x->rc= y->lc;
    y->lc= y->lc + x->lc +1;
    // rotation
    x->right= y->left;
    y->left=x;
    x->ht= height(x);
    y->ht = height(y);
    return y;
}
bst* rotateright(bst* x){
    bst* y;
    y= x->left;
    //updating childs
    x->lc= y->rc;
    y->rc= y->rc + x->rc +1;
    // rotaton
    x->left= y->right;
    y->right=x;
    x->ht= height(x);
    y->ht = height(y);
    return y;
}
bst* rr_rotation(bst* t){
    t= rotateleft(t);
    return t;
}
bst* ll_rotation(bst* t){
    t= rotateright(t);
    return t;
}
bst* lr_rotation(bst* t){
    t->left= rotateleft(t->left);
    t= rotateright(t);
    return t;
}
bst* rl_rotation(bst* t){
    t->right= rotateright(t->right);
    t= rotateleft(t);
    return t;
}
int height(bst* t){
    int lh,rh;
    if(t==NULL)return 0;
    if(t->left==NULL)lh=1;
    else lh = 1+ t->left->ht;
    if(t->right==NULL)rh=1;
    else rh = 1 + t->right->ht;
    if(lh>rh)return lh;
    else return rh;
}
int bf(bst* t){
    return (height(t->left) - height(t->right));
}
bst* fixbf_learn(bst* root, string data){
    if(bf(root)==-2){
            if(data > root->right->data) root= rr_rotation(root); //right skew
            else root= rl_rotation(root); // right-left skew
    }
    else if(bf(root)==2){
            if(data < root->left->data) root= ll_rotation(root); //left skew
            else root= lr_rotation(root); // left-right skew
        }
    root->ht = height(root); //update height
    return root;
}
bst* fixbf_forget(bst* root){
    if( bf(root) > 1 ){
        if( bf(root->left) >= 0 ){
            root = ll_rotation(root); // left skew
        }
        else root = lr_rotation(root); // left-right skew
    }
    else if( bf(root) < -1 ){
        if( bf(root->right) <= 0 ){
            root= rr_rotation(root); // right skew
        }
        else root= rl_rotation(root); // right-left skew
    }
    root->ht = height(root); //update height
    return root;
}
