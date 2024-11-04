#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n];
    vector<int> in(n, 0);
    vector<int> dist(n, 0);
    vector<int> path(n);
    vector<bool> allow(n, 0);
    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v , --u, --v;
        edge[u].push_back(v);
        in[v]++;
    }

    queue<int> qu;
    dist[0] = 1;
    path[0] = 0;
    allow[0] = 1;
    for(int i = 0; i < n; i++) if(!in[i]) qu.push(i); 
    
    while(qu.size())
    {
        int i = qu.front();
        qu.pop();

        for(int j : edge[i]) 
        {
            if(dist[j] < dist[i] + 1 && allow[i])
            {
              dist[j] = dist[i] + 1;
              path[j] = i;
              allow[j] = 1;
            }
            
            if(!(--in[j])) qu.push(j);
        }
    }

    if(!dist[n - 1]) {cout << "IMPOSSIBLE"; return 0;}
    cout << dist[n - 1] << '\n';
    vector<int> soln;
    soln.push_back(n - 1);
    int u = path[n - 1];
    while(u)
    {
        soln.push_back(u);
        u = path[u];
    } 
    soln.push_back(0);
    reverse(soln.begin(), soln.end());
    for(int i : soln) cout << i + 1 << ' ';
}