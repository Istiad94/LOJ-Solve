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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

bool taken[28];
int n,k;
string s;
vector<char>result;
int state;

void call()
{
    if(state<k)
    {
        if(result.size()==n)
        {
            for(int i=0;i<n;i++)
                pf("%c",result[i]);
            pf("\n");
            state++;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(taken[i]==false)
            {
                taken[i] = true;
                result.push_back(s[i]);
                call();
                taken[i] = false;
                result.pop_back();
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mem(taken,false);

    char alpha [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int test;
    scanf("%d",&test);
    for(int c=1;c<=test;c++)
    {
        scanf("%d%d",&n,&k);
        s.clear();
        result.clear();
        mem(taken,false);
        state = 0;
        for(int i=0;i<n;i++)
            s.push_back(alpha[i]);
        pf("Case %d:\n",c);
        call();
    }
    return 0;
}
