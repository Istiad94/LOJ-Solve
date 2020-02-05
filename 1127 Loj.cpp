#include<bits/stdc++.h>
using namespace std;
#define all(n) n.begin(),n.end()
typedef long long ll;

ll a[35],limit;
vector<ll>L,H;

void gSum(ll i,ll w,ll sum=0,ll flag=false)
{
    if(sum>w)   return;
    if(i==limit)
    {
        if(!flag)    L.push_back(sum);
        else         H.push_back(sum);
        return;
    }
    gSum(i+1,w,sum,flag);
    gSum(i+1,w,sum+a[i],flag);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    ll test,n,w,k=0;
    cin>>test;

    while(test--)
    {
        cin>>n>>w;
        L.clear();
        H.clear();
        for(int i=0;i<n;i++)    cin>>a[i];
        limit = n/2;
        gSum(0,w);
        limit = n;
        gSum(n/2,w,0,true);
        sort(all(L)),sort(all(H));

        int ans = 0;
        for(int i=0;i<L.size();i++)
            ans += upper_bound(all(H),w-L[i])-lower_bound(all(H),0);

        cout<<"Case "<<++k<<": "<<ans<<endl;
    }

    return 0;
}
