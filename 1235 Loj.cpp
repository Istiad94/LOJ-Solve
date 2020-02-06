#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>sum[2];
ll coin[20];

void gS(ll i,ll l,ll k,ll s=0,ll f=0)
{
    if(s>k) return;
    if(i==l)
    {
        sum[f].push_back(s);
        return;
    }
    gS(i+1,l,k,s,f);
    gS(i+1,l,k,s+coin[i],f);
    gS(i+1,l,k,s+coin[i]*2,f);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll test,n,m;
    cin>>test;
    for(ll k=1;k<=test;k++)
    {
        sum[0].clear();
        sum[1].clear();
        cin>>n>>m;
        for(int i=0;i<n;i++)    cin>>coin[i];
        gS(0,n/2,m,0,0);
        gS(n/2,n,m,0,1);
        sort(sum[0].begin(),sum[0].end());
        sort(sum[1].begin(),sum[1].end());
        string flag = "No";
        for(auto x : sum[0])
            if(binary_search(sum[1].begin(),sum[1].end(),m-x))
            {
                flag = "Yes";
                break;
            }
        cout<<"Case "<<k<<": "<<flag<<endl;
    }
    return 0;
}
