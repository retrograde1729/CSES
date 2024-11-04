#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(ll i : arr) ans += abs(arr[n / 2] - i);
    cout << ans;
}