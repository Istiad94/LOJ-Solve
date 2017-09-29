#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 100001
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int tree[8*MAX];
int a[MAX];
int m=2147483647;

void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]=a[b];
        return;
    }

    int l = 2*n;
    int r = 2*n + 1;
    int mid = (b+e)/2;

    init(l, b, mid);
    init(r, mid+1, e);

    tree[n]=min(tree[l],tree[r]);
}

int query(int n, int b, int e, int i, int j)
{

    if(i>e||j<b)
        return m;

    if(b>=i && e<=j)
    {
        if(i==j)
            return a[i];
        else
            return tree[n];
    }

    int l = 2*n;
    int r = 2*n + 1;
    int mid = (b+e)/2;

    int p1 = query(l, b, mid,i,j);
    int p2 = query(r, mid+1, e,i,j);

    return min(p1,p2);

}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,i,j,t;

    sf("%d",&t);

    for(int c=1;c<=t;c++)
    {
        pf("Case %d:\n",c);
        sf("%d%d",&n,&q);

        for(int i=1;i<=n;i++)
            sf("%d",&a[i]);

        init(1,1,n);

        while(q--)
        {
            sf("%d%d",&i,&j);
            pf("%d\n",query(1,1,n,i,j));
        }
    }

    return 0;
}
