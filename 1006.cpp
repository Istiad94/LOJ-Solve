#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

ull a,b,c,d,e,f,n;

ull DP[10006];

ull fn(ull n)
{
    if(n==0)
        return a;
    else if(n==1)
        return b;
    else if(n==2)
        return c;
    else if(n==3)
        return d;
    else if(n==4)
        return e;
    else if(n==5)
        return f;
    else if(DP[n]!=0)
        return DP[n];
    else
        return DP[n] = (fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    sif(t);
    for(int i=1;i<=t;i++)
    {
        sf("%llu %llu %llu %llu %llu %llu %llu",&a,&b,&c,&d,&e,&f,&n);
        pf("Case %d: %llu\n",i,fn(n)%10000007);
        memset(DP,0,sizeof(DP));
    }

    return 0;
}
