#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m;

void dfs(vector<vector<char>>& v, int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] == '#') return;
    v[i][j] = '#';
    dfs(v, i + 1, j);
    dfs(v, i - 1, j);
    dfs(v, i, j + 1);
    dfs(v, i, j - 1);
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int room = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == '.')
            {
                room++;
                dfs(v, i, j);
            }
        }
    }

    cout << room << '\n';
}