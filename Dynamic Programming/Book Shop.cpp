#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int k = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> price(n, vector<int> (2, 0));
    for(int i = 0; i < n; i++) cin >> price[i][0];
    for(int i = 0; i < n; i++) cin >> price[i][1];
    vector<int> dp(x + 1, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = x; j >= price[i][0]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i][0]] + price[i][1]);
        }
    }

    cout << dp[x] << '\n';
}