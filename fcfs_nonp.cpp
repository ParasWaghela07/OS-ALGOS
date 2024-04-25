#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int>p={1,2,3,4,5,6};
      vector<int>at={0,1,2,3,4,5};
      vector<int>bt={3,3,3,3,3,3};

    for(int i=0;i<p.size()-1;i++){
        for(int j=0;j<p.size()-1;j++){
            if(at[j]>at[j+1]){
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }

    vector<int>ct(p.size());
    vector<int>tat(p.size());
    vector<int>wt(p.size());


    int curr=0;
    for(int i=0;i<p.size();i++){
        curr+=bt[i];
        ct[i]=curr;
    }

    for(int i=0;i<p.size();i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

      for(int i=0;i<p.size();i++){
  	cout<<"p"<<p[i]<<"  "<<"at:"<<at[i]<<"  "<<"bt:"<<bt[i]<<"  "<<"ct:"<<ct[i]<<"  "<<"tat:"<<tat[i]<<"  "<<"wt:"<<wt[i]<<endl;
  }

  float avg_tat=0;
  float avg_wt=0;

  for(int i=0;i<tat.size();i++){
    avg_tat+=tat[i];
    avg_wt+=wt[i];
  }

  avg_tat=avg_tat/float(tat.size());
  avg_wt=avg_wt/float(wt.size());

  cout<<"AVG TAT :- "<<avg_tat<<endl;
  cout<<"AVG WT :- "<<avg_wt<<endl;

}