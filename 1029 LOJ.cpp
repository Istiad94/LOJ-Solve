#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

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
class edge
{
public:

    int u,v,w;
    edge(int a,int b,int c)
    {
        u = a, v = b, w = c;
    }
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

int p[110],r[110];
vector<edge>E;

void reset(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i] = i;
        r[i] = 1;
    }
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u!=v)
    {
        if(r[u]>=r[v])  p[v]=p[u],r[u]+=r[v];
        else            p[u]=p[v],r[v]+=r[u];
        return true;
    }
    return false;
}

double Kruskal(int n,bool f)
{
    int e = 0,bc = 0,wc = 0;
    for(int i=0;i<E.size();i++)
    {
        int u = E[i].u;
        int v = E[i].v;
        if(makePair(u,v))
        {
            bc+=E[i].w;
            if(++e==n-1)    break;
        }
    }
    e = 0;
    reset(n);
    for(int i=E.size()-1;i>=0;i--)
    {
        int u = E[i].u;
        int v = E[i].v;
        if(makePair(u,v))
        {
            bc+=E[i].w;
            if(++e==n-1)    break;
        }
    }
    double avg = (1.0*bc)/2.0;
    if((int)avg==avg)
        printf("%d\n",(int)avg);
    else
        printf("%d/2\n",bc);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,a,b,c;

    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        E.clear();
        scanf("%d",&n);
        reset(n+1);
        printf("Case %d: ",k);
        while(scanf("%d%d%d",&a,&b,&c))
        {
            if(!a&&!b&&!c)  break;
            E.push_back(edge(a,b,c));
        }
        sort(all(E));
        double best  = Kruskal(n+1,true);
    }

    return 0;
}
