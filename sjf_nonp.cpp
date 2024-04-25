#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p = {1, 2, 3, 4, 5};
    vector<int> at = {1,3,6,7,9};
    vector<int> bt = {7,3,2,10,8};

    vector<int> ct(p.size());

    vector<int>tempbt=bt;

    int processes = p.size();
    int time = 0;

    while (processes)
    {
        int index = -1;
        int b = INT_MAX;
        for (int i = 0; i < p.size(); i++)
        {
            if (tempbt[i] == 0)
                continue;

            if (at[i] <= time)
            {
                if (tempbt[i] < b)
                {
                    index = i;
                    b = tempbt[i];
                }
            }
        }

        if (index != -1)
        {
            time+=bt[index];
            ct[index]=time;
            processes--;
            tempbt[index]=0;
        }
        else{
            time++;
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