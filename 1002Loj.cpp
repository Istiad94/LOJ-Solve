#include<bits/stdc++.h>
 
using namespace std;
 
/// M A C R O Starts Here
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define F first
#define S second
#define uniq(v) v.resize(unique(all(v)) - v.begin())
 
typedef long long ll;
typedef unsigned long long ull;
 
int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};
 
/// Template Starts here
 
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}
 
template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}
/// Template Ends here
 
/// Functions Starts here
 
/// Bit-masking
int Set(int N,int pos){return N=N|(1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & ((ll)1<<pos));}
 
bool isPal(string s)
{
    int half = s.size()/2;
    for(int i=0,j=s.size()-1; i<half; i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}
 
double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}
 
bool inBound(int x,int y,int r,int c)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}
 
ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
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
 
/// Functions Ends here
 
int p[505],r[505];
vector<int>adj[505],cost[505];
bool visit[505];
int maxCost[505];
vector<pair<int,pii> >edges;
 
void reset(int n)
{
    edges.clear();
    for(int i=0;i<=n;i++)
    {
        adj[i].clear();
        cost[i].clear();
        visit[i] = false;
        maxCost[i] = INF;
        p[i] = i;
        r[i] = 1;
    }
}
 
void input(int m)
{
    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(all(edges));
}
 
int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}
 
bool Union(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
    {
        p[v] = u;
        r[u]+=r[v];
    }
    else
    {
        p[u] = v;
        r[v]+=r[u];
    }
    return true;
}
 
void Kruskal(int n)
{
    int e = 0;
    for(auto edge : edges)
    {
        int u = edge.S.F;
        int v = edge.S.S;
        int c = edge.F;
        if(Union(u,v))
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
            if(++e==n-1)    break;
        }
    }
}
 
void BFS(int s)
{
    queue<int>q;
    q.push(s);
    maxCost[s] = 0;
    visit[s] = true;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int c = cost[u][i];
            if(visit[v] == false)
            {
                visit[v] = true;
                q.push(v);
                maxCost[v] = max(maxCost[u],c);
            }
        }
    }
}
 
void printSolution(int CaseNo,int n,int m,int src)
{
    cout<<"Case "<<CaseNo<<":"<<endl;
    for(int node=0;node<n;node++)
    {
        if(visit[node]==false)
            cout<<"Impossible"<<endl;
        else
            cout<<maxCost[node]<<endl;
    }
}
 
int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    int test;
    cin>>test;
 
    for(int kase=1; kase<=test; kase++)
    {
        int n,m,src;
        cin>>n>>m;
        reset(n);
        input(m);
        cin>>src;
        Kruskal(n);
        BFS(src);
        printSolution(kase,n,m,src);
    }
    return 0;
}
