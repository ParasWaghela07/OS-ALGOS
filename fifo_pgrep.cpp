#include<bits/stdc++.h>
using namespace std;

bool found(char &c,string &f){
    for(int i=0;i<f.size();i++){
        if(f[i]==c){
            return true;
        }
    }

    return false;
}

int main(){
    int pgf;
    cout<<"Enter no of frames"<<endl;
    cin>>pgf;

    string s;
    cout<<"String : ";
    cin>>s;

    int index=0;

    string f;

    int miss=0;
    int hit=0;

    for(int i=0;i<s.size();i++){
        if(f.size()<pgf){
            miss++;
            f.push_back(s[i]);
        }
        else{
            if(found(s[i],f)){
                hit++;
            }
            else{
                f[index]=s[i];
                index++;
                index=index%pgf;
                miss++;
            }
        }
    }

    cout<<"Miss :- "<<miss<<endl;
    cout<<"Hit :- "<<hit<<endl;

}