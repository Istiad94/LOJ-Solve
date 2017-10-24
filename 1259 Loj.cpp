#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

vector<bool>prime(10000001, true);
vector<int>P;

void sieve()
{
    int size = 10000001;
    int root = sqrt(size);
    prime[0]=prime[1]=false;

    for(int i=4;i<size;i+=2)
        prime[i]=false;
    for(int i=3;i<=root;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i*2)
                prime[j]=false;
    int range = (size/2+5000);
    for(int i=2;i<=range;i++)
        if(prime[i])
            P.push_back(i);
}

void fastScan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    int t,n;

    fastScan(t);

    for(int kase=1;kase<=t;kase++)
    {
        fastScan(n);
        printf("Case %d: ",kase);
        int count = 0;
        int L = n/2;
        for(int i=0;P[i]<=L;i++)
        {
            int d = n-P[i];
            if(prime[d])    count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
