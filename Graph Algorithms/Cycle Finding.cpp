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
    vector<int> par(n), vis(n, 0);
    vector<ll> dist(n, 0);

    for(ll i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        if(edge[a].find(b) == edge[a].end()) edge[a][b] = c;
        else edge[a][b] = min(edge[a][b], c);
    }

    bool flag = true;
    int rel = 0;
    
    while(flag)
    {
        flag = false;
        for(int i = 0; i < n; i++)
        {
            for(auto it = edge[i].begin(); it != edge[i].end(); it++) 
            {
                int to = it -> first;
                ll wt = it -> second;
                
                if(dist[to] > dist[i] + wt)
                {
                    par[to] = i;
                    if(rel > n) 
                    {
                        while(!vis[to])
                        {
                            vis[to] = 1;
                            to = par[to];
                        }

                        vector<int> soln;
                        int back = par[to];
                        soln.push_back(to);
                        while(back != to)
                        {
                            soln.push_back(back);
                            back = par[back];
                        }
                        soln.push_back(to);
                        reverse(soln.begin(), soln.end());
                        cout << "YES" << '\n';
                        for(int i : soln) cout << i + 1 << ' ';
                        return 0;
                    }
                  dist[to] = dist[i] + wt; 
                  flag = true;
                }
            }
        }
        rel++;
    }

    cout << "NO";
}