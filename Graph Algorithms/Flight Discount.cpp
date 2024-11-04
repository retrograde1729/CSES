#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll mxn = 1e18;
 
int main()
{
    int n, m; 
    cin >> n >> m;
    unordered_map<int,ll> forward[n];
    unordered_map<int,ll> backward[n];
    vector<ll> f_dist(n, mxn);
    vector<ll> b_dist(n, mxn);
 
    for(ll i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        if(!forward[a][b]) forward[a][b] = c;
        else forward[a][b] = min(forward[a][b], c);
        if(!backward[b][a]) backward[b][a] = c;
        else backward[b][a] = min(backward[b][a], c);
    }
 
    set<pair<ll,int>> st1;
    set<pair<ll,int>> st2;
    st1.insert({0, 0});
    st2.insert({0, n - 1});
 
    while(!st1.empty())
    {
        auto it = *st1.begin();
        ll val = it.first;
        int from = it.second;
        st1.erase(it);
        if(val >= f_dist[from]) continue;
        f_dist[from] = val;
 
        for(auto itr = forward[from].begin(); itr != forward[from].end(); itr++)
        {
            int to = itr -> first;
            ll wt = itr -> second;
            st1.insert({wt + val, to});
        }
    }
 
    while(!st2.empty())
    {
        auto it = *st2.begin();
        ll val = it.first;
        int from = it.second;
        st2.erase(it);
        if(val >= b_dist[from]) continue;
        b_dist[from] = val;
 
        for(auto itr = backward[from].begin(); itr != backward[from].end(); itr++)
        {
            int to = itr -> first;
            ll wt = itr -> second;
            st2.insert({wt + val, to});
        }
    }
 
    ll ans = mxn;
    for(int i = 0; i < n; i++)
    {
        for(auto itr = forward[i].begin(); itr != forward[i].end(); itr++)
        {
            int to = itr -> first;
            ll wt = itr -> second;
            ans = min(ans, f_dist[i] + b_dist[to] + wt / 2);
        }
    }
 
    cout << ans;
}