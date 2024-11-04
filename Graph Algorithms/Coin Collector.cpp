#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5;
int id = 0;
ll coin[mxn], amt[mxn][2];
vector<int> edge[mxn];
set<int> topo[mxn];
vector<int> num(mxn, -1), low(mxn, -1), in(mxn, 0);
vector<int> scc;
set<int> st;

void tarjen(int i)
{
    num[i] = low[i] = ++id;
    scc.push_back(i);
    st.insert(i);
    for(int j : edge[i])
    {
        if(low[j] == -1) 
        {
            tarjen(j);
            low[i] = min(low[j], low[i]);
        }
        if(st.find(j) != st.end()) low[i] = min(low[i], low[j]);
    }

    if(num[i] == low[i])
    {
        while(1)
        {
            int x = scc[scc.size() - 1];
            scc.pop_back();
            low[x] = low[i];
            st.erase(x);
            if(x == i) break;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> condense;
    for(int i = 0; i < n; i++) cin >> coin[i];
    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        edge[u].push_back(v);
    }

    for(int i = 0; i < n; i++) if(low[i] == -1) tarjen(i);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) mp[low[i]].push_back(i), condense.insert(low[i]);
    
    // for(int i : condense) cout << i << ' ';
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        for(int i : it->second) amt[it->first][0] += coin[i];
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j : edge[i])
        {   
            if(low[i] == low[j]) continue;
            if(topo[low[i]].find(low[j]) == topo[low[i]].end())
            {
                topo[low[i]].insert(low[j]);
                in[low[j]]++;
            }
        }  
    }

    queue<int> qu;
    for(int i = 0; i < mxn; i++) if(!in[i] && condense.find(i) != condense.end()) qu.push(i);
    while(qu.size())
    {
        int i = qu.front();
        qu.pop();
        for(auto it : topo[i]) 
        {
            amt[it][1] = max(amt[it][1], amt[i][0] + amt[i][1]);
            in[it]--;
            if(in[it] == 0) qu.push(it);
        }
    }

    ll ans = 0;
    for(int i = 0; i < mxn; i++) ans = max(ans, amt[i][0] + amt[i][1]);
    // for(int i = 0; i < mxn; i++) 
    // {
    //     if(condense.find(i) != condense.end())
    //     {
    //         cout << i << ' ' << amt[i][0] << " " << amt[i][1] << '\n';
    //     }
    // }
    cout << ans;
}