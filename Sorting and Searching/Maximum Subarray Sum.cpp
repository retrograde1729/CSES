#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = LLONG_MIN, carry = 0;

    for(ll i : arr)
    {
        carry += i;
        if(carry < 0) carry = 0;
        else ans = max(ans, carry);
        ans = max(ans, i);
    }

    cout << ans;

}