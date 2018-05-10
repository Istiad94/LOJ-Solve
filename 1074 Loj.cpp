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

struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
    {
        u = a,v = b,w = c;
    }
};

vector<edge>e;
int busy[201],dist[201];

int reset(int n)
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&busy[i]);
        dist[i] = INF;
    }
    e.clear();
    dist[1] = 0;
}

int cube(int s,int d)
{
    return (busy[d]-busy[s])*(busy[d]-busy[s])*(busy[d]-busy[s]);
}

void input(int r)
{
    int s,d;
    while(r--)
    {
        scanf("%d%d",&s,&d);
        e.push_back(edge(s,d,cube(s,d)));
    }
}

void BellmanFord(int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool relax = false;
        for(int j=0;j<e.size();j++)
        {
            if(dist[e[j].u] !=INF && dist[e[j].v] > dist[e[j].u] + e[j].w )
            {
                relax = true;
                dist[e[j].v] = dist[e[j].u] + e[j].w;
            }
        }
        if(relax==false)    return;
    }

    for(int j=0;j<e.size();j++)
        if(dist[e[j].u] !=INF && dist[e[j].v] > dist[e[j].u] + e[j].w )
            dist[e[j].v] = -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    int n,r,q,d,kase=0;
    while(t--)
    {
        scanf("%d",&n);
        reset(n);
        scanf("%d",&r);
        input(r);
        BellmanFord(n);
        scanf("%d",&q);
        printf("Case %d:\n",++kase);
        while(q--)
        {
            scanf("%d",&d);
            (dist[d]==INF||dist[d]<3) ? puts("?") : pif(dist[d]);
        }
    }
    return 0;
}
