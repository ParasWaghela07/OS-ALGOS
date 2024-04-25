#include<bits/stdc++.h>
using namespace std;

bool found(string &frame,int target){
	for(int i=0;i<frame.size();i++){
    	if(frame[i]==target){
        	return true;
    	}
	}
    
	return false;
}

int getLRU(unordered_map<int,int>&mp){
	int element=-1;
	int index=INT_MAX;
    
	for(auto it:mp){
    	int key=it.first;
    	int valIndex=it.second;
   	 
    	if(valIndex < index ){
        	element=key;
        	index=valIndex;
    	}
	}
    
	return element;
}

int main() {
	unordered_map<int,int>mp;
    
	int pgf;
	cout<<"Enter the number of page frames : ";
	cin>>pgf;
    
	string s;
	cout<<"Enter the string :-"<<endl;
	cin>>s;
    
	cout<<endl;
    
	int miss=0;
	int hit=0;
    
	string frame;

	for(int i=0;i<s.size();i++){
    	if(frame.size()>0){
        	if(found(frame,s[i])){
            	hit++;
            	mp[s[i]]=i;
        	}
        	else{
            	if(frame.size()<pgf){
                	frame.push_back(s[i]);
                	mp[s[i]]=i;
            	}
            	else{
            	int old=getLRU(mp);
            	mp.erase(old);
            	for(int j=0;j<frame.size();j++){
                	if(frame[j]==old){
                    	frame[j]=s[i];
                    	break;
                	}
            	}
           	 
            	mp[s[i]]=i;
            	}
            	miss++;
        	}
    	}
    	else{
        	miss++;
        	frame.push_back(s[i]);
        	mp[s[i]]=i;
    	}
	}
	cout<<endl;
	cout<<"Total miss : "<<miss<<endl;
	cout<<"Total hit : "<<hit<<endl;

}
