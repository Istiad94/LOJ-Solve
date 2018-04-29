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

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};

int getID(char c)
{
    switch(c)
    {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        default:
            return 3;
    }
}

struct node
{
    int prefix;
    node *next[4];
    node()
    {
        prefix = 0;
        for(int i=0; i<4; i++)
            next[i] = NULL;
    }
} *root;

int ans;

void insert_word(char s[])
{
    node *c = root;
    int len = 0;
    for(int i=0;s[i];i++)
    {
        int id = getID(s[i]);
        if(c->next[id]==NULL)
            c->next[id] = new node();
        c = c->next[id];
        len++;
        c->prefix++;
        ans = max(ans,len*c->prefix);
    }
}

void del(node *r)
{
    for(int i=0;i<4;i++)
        if(r->next[i])
            del(r->next[i]);
    delete(r);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        root = new node();
        ans = 0;
        char s[500];
        while(n--)
        {
            scanf("%s",s);
            insert_word(s);
        }
        printf("Case %d: ",k);
        pif(ans);
        del(root);
    }
    return 0;
}
