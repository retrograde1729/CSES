#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int rec(int i, vector<int>& v)
{
    while(!v[i]) i = (i + 1) % v.size();
    return i;
}

int main()
{
    int n;
    cin >> n;
    if(n == 1) {cout << 1; return 0;}
    vector<int> v(n, 1);
    int i = 0, j = 1;
    while(i != j)
    {
        cout << j + 1 << ' ';
        v[j] = 0;
        i = rec((j + 1) % n, v);
        j = rec((i + 1) % n, v);
    }
    cout << i + 1 << '\n';
}