#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, m = 1e6 + 1;
int dp[m];

void foo()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < 7; j++)
        {
            if(j > i) break;
            else dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
}

int main()
{
    foo();
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}