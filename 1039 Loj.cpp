#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define rep(i,n)  for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

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

bool isPal(string s)
{
    int half = s.size()/2;
    for(int i=0,j=s.size()-1;i<half;i++,j--)
        if(s[i]!=s[j])  return false;
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
        if (b&1) x = (x + y) % c;
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

map<string,int>visit,level;
string start,finish,obs[51][3];
int t,n;

char _forward(char a)
{
    if(a=='z') return 'a';
    else       return ++a;
}

char _backward(char a)
{
    if(a=='a') return 'z';
    else       return --a;
}

string add(char a,char b,char c)
{
    string t;
    t+=a;
    t+=b;
    t+=c;
    return t;
}

bool allowed(string x)
{
    for(int i=0;i<n;i++)
    {
        if(binary_search(all(obs[i][0]),x[0])&&
           binary_search(all(obs[i][1]),x[1])&&
           binary_search(all(obs[i][2]),x[2]))
           return false;
    }
    return true;
}

void bfs(string s,string f)
{
    if(s==f&&allowed(s))
    {
        cout<<"0"<<endl;
        return;
    }

    visit[s] = 1;
    level[s] = 0;
    level[f] = -1;
    queue<string>q;
    q.push(s);
    while(q.size())
    {
        string u = q.front();
        if(!allowed(u)) break;
        q.pop();
        string a1 = add(_forward(u[0]),u[1],u[2]);
        string a2 = add(_backward(u[0]),u[1],u[2]);
        string b1 = add(u[0],_forward(u[1]),u[2]);
        string b2 = add(u[0],_backward(u[1]),u[2]);
        string c1 = add(u[0],u[1],_forward(u[2]));
        string c2 = add(u[0],u[1],_backward(u[2]));

        if(allowed(a1)&&visit[a1]==0)
        {
            level[a1] = level[u] + 1;
            visit[a1] = 1;
            q.push(a1);
        }
        if(allowed(a2)&&visit[a2]==0)
        {
            level[a2] = level[u] + 1;
            visit[a2] = 1;
            q.push(a2);
        }
        if(allowed(b1)&&visit[b1]==0)
        {
            level[b1] = level[u] + 1;
            visit[b1] = 1;
            q.push(b1);
        }
        if(allowed(b2)&&visit[b2]==0)
        {
            level[b2] = level[u] + 1;
            visit[b2] = 1;
            q.push(b2);
        }
        if(allowed(c1)&&visit[c1]==0)
        {
            level[c1] = level[u] + 1;
            visit[c1] = 1;
            q.push(c1);
        }
        if(allowed(c2)&&visit[c2]==0)
        {
            level[c2] = level[u] + 1;
            visit[c2] = 1;
            q.push(c2);
        }
        if(visit[f]==1) break;
    }
    if(allowed(f)&&level[f]!=-1)
        cout<<level[f]<<endl;
    else
        cout<<"-1"<<endl;
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin>>t;

    for(int k=1;k<=t;k++)
    {
        cin>>start>>finish>>n;
        visit.clear(),level.clear();
        for(int i=0;i<n;i++)
        {
            cin>>obs[i][0]>>obs[i][1]>>obs[i][2];
            sort(all(obs[i][0]));
            sort(all(obs[i][1]));
            sort(all(obs[i][2]));
        }
        cout<<"Case "<<k<<": ";
        bfs(start,finish);
    }
    return 0;
}
