#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod  1000000007

ll __gcd(ll a, ll b) {
    if(a < b) return __gcd(b, a);
    if(b == 0) return a;
    return __gcd(b, a%b);
}

int main(int argc, char const *argv[]) {
    
 
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<=n-1;i++)
    {
       cin>>arr[i];
    }
 
    vector<vector<ll> > dp(n, vector<ll> (101, 0));
 
    dp[0][arr[0]] = 1;
    ll sum = dp[0][1];
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                for(int g = 1; g <= 100; g++) {
                    int new_gcd = __gcd(g, arr[i]);
                    dp[i][new_gcd] = (dp[i][new_gcd] + dp[j][g])%mod;
                }
            }
        }
        dp[i][arr[i]] += 1;
        sum = (sum + dp[i][1])%mod;
    }
    cout<<sum;
    
    return 0;
}