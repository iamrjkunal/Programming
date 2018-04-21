#include <bits/stdc++.h>
using namespace std;


int main() {
	vector<string> Alphabets(26);
	int code;
	int flag=0;
	vector<string> encoder;
	vector<int> dec_inp ;
    iota(Alphabets.begin(), Alphabets.end(), 'A');
	for(int i=0;i<26;i++){
	    encoder.push_back(Alphabets[i]);
	}
    vector<string> alphabets(26);
    iota(alphabets.begin(), alphabets.end(), 'a');
	for(int i=0;i<26;i++){
	    encoder.push_back(alphabets[i]);
	}
    encoder.push_back("0");
    encoder.push_back("1");
    encoder.push_back("2");
    encoder.push_back("3");
    encoder.push_back("4");
    encoder.push_back("5");
    encoder.push_back("6");
    encoder.push_back("7");
    encoder.push_back("8");
    encoder.push_back("9");
	encoder.push_back(" ");
	encoder.push_back("clear");
	//cout<<encoder.size();
	/*
	for(int i=0;i<encoder.size();i++){
	    cout<<encoder[i]<<endl;
	}
	*/

	cin >> code;
	while(code!=-1){
	    dec_inp.push_back(code);
	    cin>> code;
	}
	/*
	for(int i=0;i<dec_inp.size();i++){
	    cout<< dec_inp[i]<<endl;
	}
	*/
	string output="";
	for(int idx=0;idx<dec_inp.size();idx++){
	    if(dec_inp[idx]>encoder.size()){
            cout<< "Archive is corrupted!";
            return 0;
        }
		if(dec_inp[idx]==63){
		    int aaa= encoder.size()- 1 ;
		   // cout << " size :: " << encoder.size() << endl ;
	        for(int i=aaa;i >= 64;i--){
	            encoder.erase(encoder.begin()+i);
	        }
	        flag=0;
	       // cout << " size :: " << encoder.size() << endl ;
	        continue ;
	    }
	    if(flag==1){
	        //cout << 00 ;
	        if(idx>0 && flag > 0){
	            if(dec_inp[idx]==encoder.size()){
	                encoder.push_back(encoder[dec_inp[idx-1]]+encoder[dec_inp[idx-1]][0]);
	                output += (encoder[dec_inp[idx-1]]+encoder[dec_inp[idx-1]][0]);
	              //  cout << encoder[dec_inp[idx]] << flag << " << "<< endl ;
					continue ;
					// cout << output << endl ;
	            }
	            else if(dec_inp[idx] < encoder.size()){
	                encoder.push_back(encoder[dec_inp[idx-1]]+encoder[dec_inp[idx]][0]);
	                output +=encoder[dec_inp[idx]];
	              //  cout << encoder[dec_inp[idx]]<< flag << " >> " << endl ;
					continue ;
	            }
	        }

	    }
	    if(flag==0 || idx==0){
	        // cout << 11 ;
	        
	        output += encoder[dec_inp[idx]];
	     //   cout << encoder[dec_inp[idx]] << flag<< endl ;
	        flag=1;
			// cout << output << endl ;
	    }
	}
	cout<<output;
	return 0;
}
