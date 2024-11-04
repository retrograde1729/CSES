#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n];
    vector<int> move(n);
    vector<int> vis(n, 0);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(q.size())
    {
        int node = q.front();
        q.pop();

        for(int i : edge[node])
        {
            if(vis[i]) continue;
            if(i == n - 1)
            {
                vector<int> soln;
                soln.push_back(n);
                while(node)
                {
                    soln.push_back(node + 1);
                    node = move[node];
                }
                soln.push_back(1);
                reverse(soln.begin(), soln.end());

                cout << soln.size() << '\n';
                for(int i : soln) cout << i << ' ';
                return 0;
            }

            move[i] = node;
            vis[i] = 1;
            q.push(i);
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}