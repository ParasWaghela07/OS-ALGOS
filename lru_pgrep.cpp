#include<bits/stdc++.h>
using namespace std;

int getlru(unordered_map<int,int>&mp){
    int index=INT_MAX;
    int element=-1;

    for(auto it:mp){
        int val=it.first;
        int i=it.second;

        if(i<index){
            index=i;
            element=val;
        }
    }

    return element;
}

bool found(char &c,string &f){
    for(int i=0;i<f.size();i++){
        if(f[i]==c){
            return true;
        }
    }

    return false;
}

int main(){

    unordered_map<int,int>mp;
    int pgf;
    cout<<"Enter no of frames"<<endl;
    cin>>pgf;

    string s;
    cout<<"String : ";
    cin>>s;

    string f;

    int miss=0;
    int hit=0;

    for(int i=0;i<s.size();i++){
        if(f.size()<pgf){
            if(found(s[i],f)){
                hit++;
                mp[s[i]]=i;
            }
            else{
                miss++;
                f.push_back(s[i]);
                mp[s[i]]=i;
            }
        }
        else{
            if(found(s[i],f)){
                hit++;
                mp[s[i]]=i;
            }
            else{
                int old=getlru(mp);
                mp.erase(old);

                for(int j=0;j<f.size();j++){
                    if(f[j]==old){
                        f[j]=s[i];
                        break;
                    }
                }

                mp[s[i]]=i;
                miss++;
            }
        }
    }

    cout<<"Miss :- "<<miss<<endl;
    cout<<"Hit :- "<<hit<<endl;

}