#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll mxn = 1e15;
 
int main()
{
    int n, m; 
    cin >> n >> m;
    unordered_map<int,ll> edge[n];
    unordered_set<int> arr[n];
    unordered_set<int> effect;
    vector<ll> dist(n, mxn);
    for(ll i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        if(edge[a].find(b) == edge[a].end()) edge[a][b] = -1LL * c;
        else edge[a][b] = min(edge[a][b], -1LL * c);
        arr[b].insert(a);
    }
    
    queue<int> qu;
    qu.push(n - 1);
    effect.insert(n - 1);

    while(qu.size())
    {
        int node = qu.front();
        qu.pop();
        for(auto it = arr[node].begin(); it != arr[node].end(); it++)
        {
            if(effect.find(*it) != effect.end()) continue;
            effect.insert(*it);
            qu.push(*it);
        }
    }

    bool flag = true;
    int rel = 0;
    dist[0] = 0;
    
    while(flag)
    {
        flag = false;
        for(int i = 0; i < n; i++)
        {
            if(dist[i] == mxn) continue;
            for(auto it = edge[i].begin(); it != edge[i].end(); it++) 
            {
                int to = it -> first;
                ll wt = it -> second;
                
                if(dist[to] > dist[i] + wt)
                {
                  if(rel > n && effect.find(to) != effect.end()) {cout << -1; return 0;}
                  else if(rel > 2 * n && effect.find(to) == effect.end()) {cout << -1LL * dist[n - 1]; return 0;}
                  dist[to] = dist[i] + wt; 
                  flag = true;
                }
            }
        }
        rel++;
    }
 
    cout << -1LL * dist[n - 1];
}