#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

/*
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
*/

using namespace std;

/// M A C R O Starts Here
#define MOD 100000007
#define MOD2 998244353
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
#define edge_pair pair<ll,pll>
#define F first
#define S second
#define uniq(v) v.resize(unique(all(v)) - v.begin())
#define howMany(v,L,R) (upper_bound(all(v),R)-lower_bound(all(v),L))
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define bs_find(array,value) binary_search(all(array),value)

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

int lp[46500];
vector<ll>prime;
void sieve(int limit = 46500)
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

/// Functions Ends here

const ll M = 1e9+7;
vector<pll>pf;

ll bigPow(ll n, ll p)
{
    if(!p)   return 1%M;
    if(p&1)
    {
        ll x = (bigPow(n,p-1)%M*(n%M))%M;
        x = (x+M)%M;
        return x;
    }
    else
    {
        ll ret = bigPow(n,p/2)%M;
        return (((ret*ret)%M)+M)%M;
    }
}

void factorize(ll n,ll m)
{
    pf.clear();
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            ll f = 0;
            while(n%prime[i]==0)
            {
                f++;
                n/=prime[i];
            }
            pf.push_back({prime[i],m*f+1});
        }
    }
    if(n>1) pf.push_back({n,m+1});
}

ll solve()
{
    ll u = 1,d = 1;
    for(auto factor : pf)
    {
        u = u * (bigPow(factor.F,factor.S)-1);
        u = ((u%M)+M)%M;
        d = d * (factor.F-1);
        d = ((d%M)+M)%M;
    }
    d = bigPow(d,M-2);
    return ((u*d)%M+M)%M;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    ll test,n,m;
    sieve();
    cin>>test;
    for(int kase = 1;kase<=test;kase++)
    {
        cin>>n>>m;
        factorize(n,m);
        cout<<"Case "<<kase<<": "<<solve()<<endl;
    }

    return 0;
}
