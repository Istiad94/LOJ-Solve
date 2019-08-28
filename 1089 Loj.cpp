#include<bits/stdc++.h>
/*
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
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
#define howMany(v,L,R) (upper_bound(all(v),R)-lower_bound(all(v),L))

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
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & ((ll)1<<pos));}

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
vector<ll>l,r;

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int test;
    scanf("%d",&test);
    for(int kase =1;kase<=test;kase++)
    {
        ll n,q,x,y;
        l.clear();
        r.clear();
        scanf("%lld%lld",&n,&q);
        while(n--)
        {
            scanf("%lld%lld",&x,&y);
            l.push_back(x);
            r.push_back(y);
        }
        sort(all(l));
        sort(all(r));
        printf("Case %d:\n",kase);
        while(q--)
        {
            scanf("%lld",&x);
            ll f1 = upper_bound(all(l),x)-l.begin();
            ll f2 = upper_bound(all(r),x-1)-r.begin();
            printf("%lld\n",f1-f2);
        }
    }
    return 0;
}
