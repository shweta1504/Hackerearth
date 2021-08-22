#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<ll>

ll dp[2005][2005][8];
ll kcls(vi &a1, vi &a2, int i, int j, int k)
{
    if(i== a1.size() or j==a2.size())
    {
        return 0;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll ans;
    if(a1[i] == a2[j])
    {
        ans = 1 + kcls(a1,a2,i+1,j+1,k);
        return dp[i][j][k] =ans;
    }
    else{
        ll c1 = kcls(a1,a2,i+1,j,k);
        ll c2 = kcls(a1,a2,i,j+1,k);
        ll c3 = -1;
        if(k>0)
        {
            c3 = 1+ kcls(a1,a2,i+1,j+1,k-1);
        }
        ans = max({c1,c2,c3});
        dp[i][j][k] = ans;
        return ans;
    }
}

int main()
{
    int n, m,k;
    cin>>n>>m>>k;
    vi a1(n);
    vi a2(m);
    for(int i=0;i<=n-1;i++)
    {
        cin>>a1[i];
    }
     for(int i=0;i<=m-1;i++)
    {
        cin>>a2[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<kcls(a1,a2,0,0,k);
    return 0;
}