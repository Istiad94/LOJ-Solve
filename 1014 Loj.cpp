#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL),cout.tie(NULL);

    ll test;
    cin>>test;

    for(int kase=1;kase<=test;kase++)
    {
        ll P,L;
        scanf("%lld%lld",&P,&L);
        P-=L;
        set<ll>d;
        for(ll i=1;i*i<=P;i++)
        {
            if(P%i==0)
            {
                if(i>L)     d.insert(i);
                if((P/i)>L) d.insert(P/i);
            }
        }
        if(P+L==0)
            d.insert(1);
        cout<<"Case "<<kase<<":";
        if(d.empty())
            cout<<" impossible\n";
        else
        {
            for(auto x : d)
                cout<<" "<<x;
            cout<<'\n';
        }
    }

    return 0;
}
