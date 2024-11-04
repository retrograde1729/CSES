#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<int> graph[mxn], rev[mxn];
vector<int> vis(mxn, 0);
vector<int> cc(mxn, -1);
vector<int> tree;
void forward(int i)
{
    vis[i] = 1;
    for(int j : graph[i]) if(!vis[j]) forward(j);
    tree.push_back(i);
}

void backward(int i, int id)
{
    cc[i] = id;
    for(int j : rev[i]) if(cc[j] == -1) backward(j, id);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<char> soln(m);
    for(int i = 0; i < n; i++)
    {
        char c1, c2;
        int n1, n2;
        cin >> c1 >> n1 >> c2 >> n2, --n1, --n2;
        if(c1 == '+' && c2 == '+')
        {
            graph[2 * n1 + 1].push_back(2 * n2);
            rev[2 * n2].push_back(2 * n1 + 1);
            graph[2 * n2 + 1].push_back(2 * n1);
            rev[2 * n1].push_back(2 * n2 + 1);
        }
        if(c1 == '+' && c2 == '-')
        {
            graph[2 * n1 + 1].push_back(2 * n2 + 1);
            rev[2 * n2 + 1].push_back(2 * n1 + 1);
            graph[2 * n2].push_back(2 * n1);
            rev[2 * n1].push_back(2 * n2);
        }
        if(c1 == '-' && c2 == '+')
        {
            graph[2 * n1].push_back(2 * n2);
            rev[2 * n2].push_back(2 * n1);
            graph[2 * n2 + 1].push_back(2 * n1 + 1);
            rev[2 * n1 + 1].push_back(2 * n2 + 1);
        }
        if(c1 == '-' && c2 == '-')
        {
            graph[2 * n1].push_back(2 * n2 + 1);
            rev[2 * n2 + 1].push_back(2 * n1);
            graph[2 * n2].push_back(2 * n1 + 1);
            rev[2 * n1 + 1].push_back(2 * n2);
        }
    }

    for(int i = 0; i < 2 * m; i++) if(!vis[i]) forward(i);

    int id = 0;
    
    for(int i = tree.size() - 1; i >= 0; i--) if(cc[tree[i]] == -1) backward(tree[i], ++id);

    for(int i = 0; i < m; i++)
    {
        if(cc[2 * i] == cc[2 * i + 1]) {cout << "IMPOSSIBLE"; return 0;}
        soln[i] = (cc[2 * i] > cc[2 * i + 1]) ? '+' : '-';
    }

    for(char c : soln) cout << c << ' ';
}