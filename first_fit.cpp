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

        bool hua=false;
        for(int i=0;i<p.size();i++){
            if(p[i]>=s){
                p[i]=0;
                cout<<"Entered successfully"<<endl<<endl;
                hua=true;
                break;
            }
        }

        if(hua==false){
            cout<<"NO SPACE"<<endl<<endl;
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