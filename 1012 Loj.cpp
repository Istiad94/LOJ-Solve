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

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

vector<string>graph;
int r,c;

int BFS(int i, int j)
{
    queue<pii>q;
    q.push(pii(i,j));
    int count = 0;
    graph[i][j] = '#';

    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;

        q.pop();

        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx>=0 && vx < r && vy>=0 && vy < c && graph[vx][vy]!='#')
            {
                graph[vx][vy] = '#';
                count++;
                q.push(pii(vx, vy));
            }
        }
    }
    return ++count;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    char s[MAX];

    scanf("%d", &test);

    for(int kase = 1; kase<=test;kase++)
    {
        graph.clear();

        printf("Case %d: ",kase);
        scanf("%d%d",&c,&r);

        for(int i=0;i<r;i++)
        {
            scanf("%s",s);
            graph.push_back(s);
        }

        bool ans=false;

        for(int i=0;i<r;i++)
        {
            if(ans) break;
            for(int j=0;j<c;j++)
                if(graph[i][j]=='@')
                {
                    printf("%d\n",BFS(i,j));
                    ans = true;
                    break;
                }
        }

    }

    return 0;
}
