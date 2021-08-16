#include<bits/stdc++.h>
using namespace std;

int main() 
{
int num;
cin >> num;
int a[num];
for(int i=0;i<num;i++)
{
  cin >> a[i];
}
if(a[num-1]%10==0)
{
 cout << "Yes" << endl;
}
else
{  
     cout << "No" << endl;
}          

}