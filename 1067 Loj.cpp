#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6;
const ll MOD = 1e6+3;

ll fact[N];

void dp()
{
    fact[0] = 1;
    for(int i=1;i<=1e6;i++)
        fact[i]=((fact[i-1]%MOD*(i%MOD))%MOD);
}

ll bigMod(ll n,ll p)
{
    if(!p)  return 1%MOD;
    if(p&1)
        return (bigMod(n,p-1)%MOD*(n%MOD))%MOD;
    else
    {
        ll r = bigMod(n,p/2)%MOD;
        return (r*r)%MOD;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    dp();
    ll test;
    cin>>test;
    for(int kase = 1;kase<=test;kase++)
    {
        ll n,r;
        cin>>n>>r;
        ll ans = (fact[r]*fact[n-r])%MOD;
        ans = bigMod(ans,MOD-2);
        ans = (ans*fact[n])%MOD;
        cout<<"Case "<<kase<<": "<<ans<<endl;
    }
    return 0;
}
