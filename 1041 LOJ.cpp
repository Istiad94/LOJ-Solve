#include<bits/stdc++.h>
#include<unordered_map>
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
class E
{
public:
    int u,v,w;
    E(int a,int b,int c)
    {
        u = a,v = b,w = c;
    }
    bool operator < (const E &p) const
    {
        return w < p.w;
    }
};
vector<E>e;
map<string,int>id;
int p[110],r[110];

void reset()
{
    e.clear();
    id.clear();
    for(int i=1;i<=109;i++)
        p[i] = i, r[i] = 1;
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int u,int v)
{
    int a = Find(u);
    int b = Find(v);
    if(a!=b)
    {
        if(r[a]>=r[b]) r[a]+=r[b],p[b]=p[a];
        else           r[b]+=r[a],p[a]=p[b];
        return true;
    }
    return false;
}

void Kruskal(int n)
{
    int edge = 0,s = 0;
    bool flag = false;
    for(int i=0;i<e.size();i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        if(makePair(u,v))
        {
            s+=e[i].w;
            if(++edge==n-1)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
        printf("%d\n",s);
    else
        printf("Impossible\n");
}

void input(int m)
{
    char a[55],b[55];
    int c,n=1;
    while(m--)
    {
        scanf("%s%s%d",a,b,&c);
        int u = id[a];
        int v = id[b];
        if(!u)  id[a]=n++,u=n-1;
        if(!v)  id[b]=n++,v=n-1;
        e.push_back(E(u,v,c));
    }
    n--;
    sort(all(e));
    Kruskal(n);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,m;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        reset();
        scanf("%d",&m);
        printf("Case %d: ",i);
        input(m);
    }

    return 0;
}
