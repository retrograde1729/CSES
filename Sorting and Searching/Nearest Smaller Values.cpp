#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), soln(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        while(arr[j] > arr[i])
        {
            if(!soln[j]) break;
            j = soln[j] - 1;
        }
        if(arr[j] < arr[i]) soln[i] = j + 1;
        else soln[i] = 0;
    }

    for(int i : soln) cout << i << ' ';
}