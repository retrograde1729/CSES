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
    for(int i = 0; i < n; i++)
    {
        for(int j = c[i]; j <= x; j++)
        {
            dp[j] = (dp[j - c[i]] + dp[j]) % mod; 
        }
    }
    cout << dp[x] << '\n';
}