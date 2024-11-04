#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> arr(n, vector<int> (2));
    for(int i = 0; i < n; i++) cin >> arr[i][0], arr[i][1] = i + 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        int y = x - arr[i][0];
        int j = i + 1, k = n - 1;
        while(j < k)
        {
            if(arr[j][0] + arr[k][0] > y) k--;
            else if(arr[j][0] + arr[k][0] < y) j++;
            else {cout << arr[i][1] << ' ' << arr[j][1] << ' ' << arr[k][1]; return 0;}
        }
    }

    cout << "IMPOSSIBLE";
}