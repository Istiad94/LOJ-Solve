#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

vector<int>adj[1001];
int cnt[1001];
bool visit[1001];

void BFS(int s)
{
    memset(visit,false,sizeof(visit));
    queue<int>q;
    visit[s] = true;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visit[adj[u][i]]==false)
            {
                visit[adj[u][i]] = true;
                cnt[adj[u][i]]++;
                q.push(adj[u][i]);
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        int k,n,m;

        cin>>k>>n>>m;

        for(int i=1;i<=n;i++)
        {
            cnt[i]=0;
            adj[i].clear();
        }

        vector<int>person(k);

        for(int i=0;i<k;i++)
        {
            cin>>person[i];
            cnt[person[i]]++;
        }

        while(m--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        for(int i=0;i<k;i++)
            BFS(person[i]);

        int ans = 0;

        for(int i=1;i<=n;i++)
            if(cnt[i]==k)
                ans++;

        printf("Case %d: %d\n",kase,ans);
        person.clear();
    }
    return 0;
}
