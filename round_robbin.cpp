#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tq=5;
    vector<int> p = {1, 2, 3, 4, 5,6};
    vector<int> at = {0,1,2,3,4,4};
    vector<int> bt = {7,4,15,11,20,9};

    vector<int> ct(p.size());

    vector<int>tempbt=bt;

    int processes = p.size();
    int time = 0;

    while (processes)
    {
        for (int i = 0; i < p.size(); i++)
        {
            if (tempbt[i] == 0)
                continue;

            if (at[i] <= time)
            {
                if(tempbt[i]>=tq){
                    tempbt[i]-=tq;
                    time+=tq;
                    if(tempbt[i]==0){
                        ct[i]=time;
                        // cout<<"P"<<p[i]<<endl;
                        processes--;
                    }
                }
                else{
                    time+=tempbt[i];
                    tempbt[i]=0;
                    ct[i]=time;
                    // cout<<"P"<<p[i]<<endl;
                    processes--;
                }
            }

            // cout<<"Time:- "<<time<<endl;

            // for(int i=0;i<tempbt.size();i++){
            //     cout<<tempbt[i]<<" ";
            // }
            // cout<<endl<<endl;
        }

        

    }

    vector<int> tat(p.size());
    vector<int> wt(p.size());

    for (int i = 0; i < p.size(); i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << "p" << p[i] << "  "
             << "at:" << at[i] << "  "
             << "bt:" << bt[i] << "  "
             << "ct:" << ct[i] << "  "
             << "tat:" << tat[i] << "  "
             << "wt:" << wt[i] << endl;
    }
    cout << endl;
    float avg_tat = 0;
    float avg_wt = 0;

    for (int i = 0; i < tat.size(); i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat = avg_tat / float(tat.size());
    avg_wt = avg_wt / float(wt.size());

    cout << "AVG TAT :- " << avg_tat << endl;
    cout << "AVG WT :- " << avg_wt << endl;
}