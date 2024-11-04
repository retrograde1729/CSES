#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    string str1 , str2;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    if(n < m)
    {
        swap(str1, str2);
        swap(n, m);
    }
    vector<int> p(m, 0), c(m, 0);
    p[0] = !(str1[0] == str2[0]);

    for(int i = 1; i < m; i++) 
    {
        if(str1[0] == str2[i]) p[i] = i;
        else p[i] = p[i - 1] + 1;
    }

    for(int i = 1; i < n; i++)
    {
        if(str1[i] == str2[0]) c[0] = i;
        else c[0] = p[0] + 1;

        for(int j = 1; j < m; j++)
        {
            if(str1[i] == str2[j]) c[j] = p[j - 1];
            else c[j] = min(p[j - 1], min(c[j - 1], p[j])) + 1;
        }

        p = c;
    }

    c = p;
    cout << c[m - 1] << '\n';   
}