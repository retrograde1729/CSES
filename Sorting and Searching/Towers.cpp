#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int main()
{
    int n;
    cin >> n;
    vector<int> lis;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        auto it = upper_bound(lis.begin(), lis.end(), k);;
        if(it != lis.end()) *it = k;
        else lis.push_back(k);
    }

    cout << lis.size();
}