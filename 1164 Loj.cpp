#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define sif(n) scanf("%d",&n)
#define lif(n) scanf("%lld",&n)
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

enum COLOR { W = 0, G = 1, B = 2};

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

/*
int lp[32001];
vector<int>prime;

void sieve(int limit = 32001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}
*/

class T
{
public:
    ll sum,prop;
    T()
    {
        sum = prop = 0;
    }
};

T tree[400000];

void upd(int n,int b,int e,int i,int j,int v)
{
    if(e<i||b>j)    return;
    if(b>=i&&e<=j)
    {
        tree[n].sum+=((e-b+1)*v);
        tree[n].prop+=v;
        return;
    }

    int l = n*2;
    int r = l+1;
    int m =(b+e)/2;

    upd(l,b,m,i,j,v);
    upd(r,m+1,e,i,j,v);

    tree[n].sum = tree[l].sum + tree[r].sum + (e-b+1)*tree[n].prop;
}

ll Q(int n,int b,int e,int i,int j,ll c=0)
{
    if(b>j||e<i)    return 0;
    if(b>=i&&e<=j)
        return tree[n].sum+(c*(e-b+1));

    int l = n*2;
    int r = l+1;
    int m =(b+e)/2;

    ll q1 = Q(l,b,m,i,j,c+tree[n].prop);
    ll q2 = Q(r,1+m,e,i,j,c+tree[n].prop);

    return q1+q2;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,q,i,j,v,t;
    sif(t);
    for(int k=1;k<=t;k++)
    {
        printf("Case %d:\n",k);

        sif(n);
        sif(q);

        for(int a=1;a<400000;a++)
            tree[a].sum = tree[a].prop = 0;

        int c;
        while(q--)
        {
            sif(c);
            sif(i);
            sif(j);
            if(!c)
            {
                sif(v);
                upd(1,1,n,++i,++j,v);
            }
            else
                printf("%lld\n",Q(1,1,n,++i,++j,0));
        }
    }
    return 0;
}

