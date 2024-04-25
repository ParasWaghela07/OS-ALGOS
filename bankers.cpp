#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    vector<vector<int>> a = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    vector<vector<int>> maxneed = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}};

    vector<int> avail = {3, 3, 2};

    vector<vector<int>> need;

    for (int i = 0; i < a.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < a[0].size(); j++)
        {
            temp.push_back(maxneed[i][j] - a[i][j]);
        }
        need.push_back(temp);
    }

    int pro = a.size();

    while (pro > 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            vector<int> curr_a = a[i];
            vector<int> curr_need = need[i];

            if (curr_need[0] == 0 && curr_need[1] == 0 && curr_need[2] == 0)
                continue;

            if (avail[0] >= curr_need[0] && avail[1] >= curr_need[1] && avail[2] >= curr_need[2])
            {
                need[i][0] = 0;
                need[i][1] = 0;
                need[i][2] = 0;

                pro--;
                ans.push_back(i);
                avail[0] += curr_a[0];
                avail[1] += curr_a[1];
                avail[2] += curr_a[2];
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        
        cout << "P" << ans[i];
        if(i==ans.size()-1) break;
        cout<<"->";
    }
}