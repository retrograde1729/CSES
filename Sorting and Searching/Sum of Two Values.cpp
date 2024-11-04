#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<vector<int>> val(n, vector<int> (2));
    for(int i = 0; i < n; i++) {cin >> val[i][0]; val[i][1] = i + 1;}
    sort(val.begin(), val.end());
    int i = 0, j = n - 1;
    while(i < j)
    {
        if(val[i][0] + val[j][0] == x) {cout << val[i][1] << ' ' << val[j][1]; return 0;}
        else if(val[i][0] + val[j][0] > x) j--;
        else i++;
    }
    
    cout << "IMPOSSIBLE";
}