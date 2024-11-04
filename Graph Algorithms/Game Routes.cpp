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
    vector<bool> allow(n, 0);

    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v , --u, --v;
        edge[u].push_back(v);
        in[v]++;
    }

    queue<int> qu;
    dist[0] = 1;
    allow[0] = 1;
    for(int i = 0; i < n; i++) if(!in[i]) qu.push(i); 
    
    while(qu.size())
    {
        int i = qu.front();
        qu.pop();

        for(int j : edge[i]) 
        {
            if(allow[i])
            {
              dist[j] = (dist[i] + dist[j]) % mod;
              allow[j] = 1;
            }
            
            if(!(--in[j])) qu.push(j);
        }
    }

    cout << dist[n - 1] % mod;
}