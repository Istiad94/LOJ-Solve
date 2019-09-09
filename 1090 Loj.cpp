#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll dp[1000005][2];
 
void preCal()
{
    int p[] = {2,3,5};
    for(int i=2;i<=1e6;i++)
    {
        int n = i;
        for(int j=0;j<=2;j++)
            while(n%p[j]==0)
            {
                n/=p[j];
                if(!j)           dp[i][0]++;
                else if(j==2)    dp[i][1]++;
            }
        if(n==2)         dp[i][0]++;
        else if(n==5)    dp[i][1]++;
        dp[i][0] += dp[i-1][0];
        dp[i][1] += dp[i-1][1];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    preCal();
 
    int test,n,r,p,q;
    cin>>test;
 
    for(int k=1;k<=test;k++)
    {
        cin>>n>>r>>p>>q;
        ll t2 = dp[n][0] - dp[r][0] - dp[n-r][0] + (dp[p][0]-dp[p-1][0])*q;
        ll t5 = dp[n][1] - dp[r][1] - dp[n-r][1] + (dp[p][1]-dp[p-1][1])*q;
        ll ans = min(t2,t5);
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
    return 0;
}
