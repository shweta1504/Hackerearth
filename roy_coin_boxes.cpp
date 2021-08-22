#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll start[1000005], end1[100005], temp[1000005], coins[100005];

int main()
{
	int n, m;
	cin>>n>>m;

	for(int i=0;i<=1000000;i++)
	{
		start[i] = end1[i] = temp[i] = coins[i] = 0;
	}
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		start[l]++;
		end1[r]++;
	}
	temp[1] = start[1];
	for(int i=2;i<=n;i++)
	{
		temp[i] = start[i] - end1[i-1] + temp[i-1];
	}
	for(int i=1;i<=n;i++)
    {
    	coins[temp[i]]++;
    }
    for(int i=n-1;i>=0;i)
    {
    	coins[i] = coins[i] = coins[i+1];
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int r;
    	cin>>r;
    	cout<<coins[r]<<endl;
    }
    return 0;
}