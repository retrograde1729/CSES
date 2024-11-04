#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> out(n);

    for(int i = 0; i < n; i++) cin >> in[i] >> out[i];
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    int i = 0, j = 0, ans = 0;
    while(i < n && j < n)
    {
        if(in[i] < out[j]) {i++; ans = max(ans, i - j);}
        else if(in[i] == out[j]) {i++; j++;}
        else j++;
    }

    cout << ans;
}