#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int mark[1000005];
vector<int>prime;

void sieve(int range=1000000)
{
    for(int i=2; i<=range; i++)
    {
        if(!mark[i])
        {
            mark[i] = i;
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&i*prime[j]<=range&&prime[j]<=i; j++)
            mark[i*prime[j]]=prime[j];
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    int t;
    ll n;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        scanf("%lld",&n);
        int res = 1;
        int root = sqrt(n);
        for(int i=0; i<prime.size()&&prime[i]*prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                int f = 1;
                while(n%prime[i]==0)
                {
                    f++;
                    n/=prime[i];
                }
                res*=f;
            }
        }
        if(n>1) res*=2;
        printf("Case %d: %d\n",k,res-1);
    }
    return 0;
}
