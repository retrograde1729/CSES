#include<bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 1;

int main()
{
    int n, id = 1;
    cin >> n;
    vector<int> t(n, 0);
    for(int i = 0; i < n; i++) cin >> t[i], --t[i];
    vector<int> cyc_id(n, -1);
    vector<int> dist(n, 0);
    vector<int> vis(n, 0);
    map<int,int> cyc_len;
    
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            // cout << i + 1 << '\n';
            vis[i] = 1;
            int u = t[i];
            
            while(!vis[u])
            {
                vis[u] = 1;
                u = t[u];
            }
            
            if(cyc_id[u] != -1)
            {
                int depth = dist[u];
                // cout << i + 1 << ' ' << u + 1 << '\n';
                // cout << dist[u] << '\n';
                int v = i;
                while(v != u)
                {
                    depth++;
                    cyc_id[v] = cyc_id[u];
                    v = t[v];
                }
                v = i;
                while(v != u)
                {
                    dist[v] = depth--;
                    v = t[v];
                }
                
                continue;
            }
            
            int len = 1;
            int v = t[u];
            cyc_id[u] = id;
            while(u != v)
            {
                len++;
                cyc_id[v] = id;
                v = t[v];
            }
            cyc_len[id] = len;
            int depth = 0;
            v = i;
            while(v != u)
            {
                depth++;
                cyc_id[v] = id;
                v = t[v];
            }
            v = i;
            while(v != u)
            {
                dist[v] = depth--;
                v = t[v];
            }
            id++;
        }
    }
    
    // for(int i = 0; i < n; i++) cout << dist[i] << ' ';
    // cout << '\n';
    // for(int i = 0; i < n; i++) cout << cyc_id[i] << ' ';
    for(int i = 0; i < n; i++) cout << dist[i] + cyc_len[cyc_id[i]] << ' ';
}