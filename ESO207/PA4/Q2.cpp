#include <bits/stdc++.h>
using namespace std;

typedef struct htnode{
   string* value;
   struct htnode* next;
   int count=0;
} htnode;
htnode* htable[1000];
htnode* new_node(string data);
htnode* searchword(htnode* ht, string word );
void insertword(htnode* ht, string word );
int hfun(string word, int len);

int max_count=1;
string maxs;


int main() {
	int n,k;
	
	for(int j=0;j<1000;j++) htable[j]=NULL;
	cin>> n;
	for(k=0;k<n;k++){
	string word;
    cin>> word;
    //cout << hfun(word, word.length()) <<endl;
    insertword(htable[hfun(word, word.length())], word);
	}
	
	cout << maxs <<endl;
    	
	return 0;
}

int hfun(string word, int len){
    int i;
    int sum=0;
    for(i=0;i<len;i++){
        sum = (sum + word[i])%1000;
    }
    //cout<< sum;
    return sum;
}
htnode* new_node (string data){
    htnode* node=new htnode;
    node->value = new string;
    *(node->value)= data;
    node->next=NULL;
    node->count= 1;
    return node;
}
htnode* searchword(htnode* ht, string word ){
    htnode* temp = ht;
    while (temp != NULL){
       if(*(temp->value)== word) return temp; 
       temp= temp->next;
    }
    return NULL;
}
void insertword(htnode* ht, string word ){
    htnode* new_nd;
    //cout<< "error" <<endl;
    htnode* ptr = searchword(ht, word );
    //cout<< "error" <<endl;
    if(ptr == NULL && ht == NULL){
        
      new_nd = new_node(word);  
      htable[hfun(word, word.length())] = new_nd;
      //cout<< "error" <<endl;
    }
    else if (ptr==NULL && ht !=NULL){
        htnode* p;
        while (ht != NULL) {
            p=ht;
            ht= ht->next;
        }
        new_nd = new_node(word);
        p->next = new_nd;
    }
    else{
        //cout<< "error" <<endl;
        (ptr->count) = (ptr->count) + 1;
        if((ptr->count) > max_count){
        max_count = ptr->count;
        maxs = *(ptr->value);
        //cout<< "error" <<endl;
        }
    }
}


