#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll dead = 0, ans = 0;
    vector<ll> finish(n, 0);
    for(int i = 0, d; i < n; i++) cin >> finish[i] >> d, dead += d;
    sort(finish.begin(), finish.end());
    for(int i = 1; i < n; i++) finish[i] += finish[i - 1];
    for(ll i : finish) ans += i;
    cout << dead - ans;
}