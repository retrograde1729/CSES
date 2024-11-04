#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m;
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
char d[4] = {'U', 'L', 'D', 'R'};

struct custom 
{
    char dir;
    int i;
    int j;
};

int main() 
{
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<custom>> s(n, vector<custom>(m));
    queue<vector<int>> q;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> v[i][j];
            if (v[i][j] == 'A') 
            {
                q.push({i, j, 0});
                v[i][j] = '#';
                s[i][j].i = -1;
                s[i][j].j = -1;
            }
        }
    }

    while (!q.empty()) 
    {
        auto it = q.front();
        q.pop();
        int i = it[0], j = it[1], dist = it[2];
        for (int k = 0; k < 4; k++) 
        {
            int ni = i + x[k], nj = j + y[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || v[ni][nj] == '#') continue;
            if (v[ni][nj] == 'B') 
            {
                cout << "YES" << '\n';
                cout << dist + 1 << '\n';
                string path = "";
                path += d[k];
                while (s[i][j].i != -1 && s[i][j].j != -1) 
                {
                    path += s[i][j].dir;
                    int pi = s[i][j].i, pj = s[i][j].j;
                    i = pi;
                    j = pj;
                }
                reverse(path.begin(), path.end());
                cout << path << '\n';
                return 0;
            }
            s[ni][nj].dir = d[k];
            s[ni][nj].i = i;
            s[ni][nj].j = j;
            v[ni][nj] = '#';
            q.push({ni, nj, dist + 1});
        }
    }

    cout << "NO" << '\n';
}