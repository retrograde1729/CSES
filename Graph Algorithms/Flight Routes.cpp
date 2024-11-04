#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll mxn = 1e15;

int main()
{
    int n, m, k; 
    cin >> n >> m >> k;
    vector<pair<int,ll>> edge[n];
    vector<vector<ll>> route(n);
    for(ll i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        edge[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty())
    {
        auto it = pq.top();
        ll val = it.first;
        int from = it.second;
        pq.pop();

        if(route[from].size() < k)
        {
            route[from].push_back(val);
            for(auto itr : edge[from])
            {
                pq.push({itr.second + val, itr.first});
            }
        }
    }

    for(int i = 0; i < k; i++) cout << route[n - 1][i] << ' ';
}