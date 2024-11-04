#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> prefix(n, 0);
    cin >> prefix[0];
    for(int i = 1; i < n; i++) cin >> prefix[i], prefix[i] += prefix[i - 1];
    ll i = 0, j = 0, t = 0;
    while(j < n)
    {
        if(prefix[j] - t == x) {ans++; j++;}
        else if(prefix[j] - t > x) t = prefix[i++];
        else j++;
    }

    cout << ans;
}