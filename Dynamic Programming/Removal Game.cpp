#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;  
const int inf = 1e8;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> prefix(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] += arr[i];
        if(i + 1 < n) prefix[i + 1] += prefix[i];
    }

    vector<vector<ll>> dp(n, vector<ll> (n, 0));
    for(int i = 0; i < n; i++) dp[i][i] = arr[i];

    for(int k = 1; k < n; k++)
    {
        for(int i = 0; i < n - k; i++)
        {
            dp[i][i + k] = prefix[i + k] - ((i) ? prefix[i - 1] : 0) - min(dp[i][i + k - 1], dp[i + 1][i + k]);
        }
    }

    cout << dp[0][n - 1] << '\n';
}