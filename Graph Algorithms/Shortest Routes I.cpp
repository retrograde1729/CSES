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
    vector<ll> dist(n, mxn);
    for(ll i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        if(!edge[a][b]) edge[a][b] = c;
        else edge[a][b] = min(edge[a][b], c);
    }

    set<pair<ll, int>> st;
    st.insert({0, 0});

    while(!st.empty())
    {
        auto it = st.begin();
        ll val = it -> first;
        int from = it -> second;
        st.erase(it);
        if(dist[from] != mxn) continue;
        dist[from] = val;
        for(auto itr = edge[from].begin(); itr != edge[from].end(); itr++)
        {
            st.insert({itr->second + val, itr->first});
        }
    }

    for(ll i : dist) cout << i << ' ';
}