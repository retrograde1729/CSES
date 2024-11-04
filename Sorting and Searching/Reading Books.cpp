#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, a = 0, b = 0;
    cin >> n;
    if(n == 1)
    {
        int x;
        cin >> x;
        cout << 2 * x;
        return 0;
    }
    vector<ll> v(n), x, y;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int i = n - 1, j = n - 2;
    while(i >= 0 && j >= 0)
    {
        if(a < b) a += v[i], x.push_back(v[i]), v[i--] = 0;
        else b += v[j], y.push_back(v[j]), v[j--] = 0;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(a > b && x[x.size() - 1] <= b) {cout << a + b; return 0;}
    if(b > a && y[y.size() - 1] <= a) {cout << a + b; return 0;}
    cout << 2LL * max(a, b);
}