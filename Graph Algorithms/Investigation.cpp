#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll mxn = 1e18;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> edge[n];
    vector<ll> dist(n, mxn);
    vector<ll> min_r(n, mxn);
    vector<ll> max_r(n, 0);
    vector<ll> path(n, 0);

    for(ll i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w, --u, --v;
        edge[u].push_back({v, w});
    }

    set<pair<ll,ll>> st; 
    dist[0] = 0;
    path[0] = 1;
    min_r[0] = 0;
    max_r[0] = 0;
    st.insert({0, 0});

    while(st.size())
    {
        auto itr = st.begin();
        ll val = itr -> first;
        ll i = itr -> second;
        st.erase(itr);

        if(dist[i] < val) continue;
        for(auto it : edge[i]) 
        {
            ll j = it.first, wt = it.second;
            if(dist[j] > dist[i] + wt)
            {
                dist[j] = dist[i] + wt;
                min_r[j] = min_r[i] + 1;
                max_r[j] = max_r[i] + 1;
                path[j] = path[i];
                if(i != n - 1) st.insert({dist[j], j});
            }
            else if(dist[j] == dist[i] + wt)
            {
                min_r[j] = min(min_r[i] + 1, min_r[j]);
                max_r[j] = max(max_r[i] + 1, max_r[j]);
                path[j] = (path[i] + path[j]) % mod;
            }
        }
    }
    
    // for(ll i = 0; i < n; i++) cout << dist[i] << ' ' << path[i] << ' ' << min_r[i] << ' ' << max_r[i] << '\n';
    cout << dist[n - 1] << ' ' << path[n - 1] << ' ' << min_r[n - 1] << ' ' << max_r[n - 1];
}