#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 1e5 + 1;

int low[mxn] = {0}, num[mxn] = {0};
vector<int> scc;
set<int> st;
vector<int> graph[mxn];
int id = 0;

void tarjen(int i)
{
    low[i] = num[i] = ++id;
    scc.push_back(i);
    st.insert(i);

    for(int j : graph[i])
    {
        if(!low[j]) 
        {
            tarjen(j);
            low[i] = min(low[i], low[j]);
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
    map<int,int> mp;

    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) if(!low[i]) tarjen(i);
    id = 1;
    for(int i = 1; i <= n; i++) if(!mp[low[i]]) mp[low[i]] = id++;
    cout << mp.size() << '\n';
    for(int i = 1; i <= n; i++) cout << mp[low[i]] << ' ';
}