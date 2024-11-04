#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<ll, vector<int>> ump;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ump.find(x - a[i] - a[j]) != ump.end())
            {
                cout << i + 1 << ' ' << j + 1 << ' ' << ump[x - a[i] - a[j]][0] << ' ' << ump[x - a[i] - a[j]][1];
                return 0;
            }
        }
        for(int j = 0; j < i; j++) ump[a[i] + a[j]] = {i + 1, j + 1};
    }
    cout << "IMPOSSIBLE";
}