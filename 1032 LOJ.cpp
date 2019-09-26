#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/// pos,cnt,big,prev
ll dp[35][50][2][2];


ll solve(string num,int p,ll sum,bool isBig,bool prev)
{
    if(p==num.size())   return sum;
    if(dp[p][sum][isBig][prev]!=-1) return dp[p][sum][isBig][prev];
    int limit = (isBig) ? 1 : num[p]-48;
    ll r = 0;
    for(int d=0;d<=limit;d++)
        r+=solve(num,p+1,sum+(prev&d),isBig|d<limit,d==1);
    return dp[p][sum][isBig][prev]=r;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;

    cin>>test;
    for(int k=1;k<=test;k++)
    {
        ll n;
        cin>>n;
        string num;
        if(n==0)    num = "0";
        while(n)
        {
            num+=(n%2+48);
            n/=2;
        }
        memset(dp,-1,sizeof(dp));
        reverse(num.begin(),num.end());
        ll ans = solve(num,0,0,0,0);
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
    return 0;
}
