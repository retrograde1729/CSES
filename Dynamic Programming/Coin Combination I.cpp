#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(auto& i : c) cin >> i;
    sort(c.begin(), c.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[j] > i) break;
            else dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }
    cout << dp[x] << '\n';
}