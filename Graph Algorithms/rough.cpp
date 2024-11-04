#include <bits/stdc++.h>
using namespace std;
// typedef long long int;

const int pp = 1e3 + 1, tt = 1e5 + 1;
int dp[pp][tt];
 
int solveMem(vector<int> & price, vector<int> & page, int i, int n, int x) {
    if(i == n || x < 0) return 0;
 
    if(dp[i][x] != -1) return dp[i][x];
    
    int op1 = INT_MIN;
    if(price[i] <= x) {
        op1 = page[i] + solveMem(price, page, i + 1, n, x - price[i]);
    }
    int op2 = 0 + solveMem(price, page, i + 1, n, x);
 
    return dp[i][x] = max(op1, op2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin>>n>>x;
 
    vector<int> price(n), page(n);
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n; i++) {
        cin>>price[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>page[i];
    }
 
    cout<<solveMem(price, page, 0, n, x);
}
