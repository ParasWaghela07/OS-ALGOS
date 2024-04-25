#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of partitions"<<endl;
    cin>>n;

    vector<int>p(n);
    cout<<"Enter partition sizes"<<endl;
    for(int i=0;i<p.size();i++){
        cin>>p[i];
    }

    int l=1;

    while(l){
        cout<<"Enter size of process"<<endl;
        int s;
        cin>>s;
        
        int index=-1;
        int val=INT_MAX;

        for(int i=0;i<p.size();i++){
            if(p[i]>=s && p[i]<val){
                val=p[i];
                index=i;
            }
        }

        if(index==-1){
            cout<<"NO SPACE"<<endl<<endl;
        }
        else{
            p[index]=0;
            cout<<"Success"<<endl;
        }

        cout<<"Status:-"<<endl;
        for(int i=0;i<p.size();i++){
            cout<<p[i];
        }

        cout<<endl;


        cout<<"Wanna continue ? 1/0"<<endl;

        cin>>l;

    }
}