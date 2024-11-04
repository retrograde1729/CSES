#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> cost;

    for(int i = 0, c; i < n; i++) {cin >> c; cost[c]++;}
    
    for(int i = 0; i < m; i++)
    {
        int l;
        cin >> l;
        auto it = cost.upper_bound(l);
        if(it == cost.begin()) cout << -1 << '\n';
        else 
        {
            if(cost.empty()) {cout << -1 << '\n'; continue;}
            --it;
            cout << it->first << '\n';
            it->second--;
            if(!it->second) cost.erase(it);
        }
    }
}