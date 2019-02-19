#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

vector<int>adj[50001],path;
int parent[50001];
bool visit[50001];

void BFS(int s,int d)
{
    memset(visit,false,sizeof(visit));
    memset(parent,0,sizeof(parent));
    visit[s] = true;
    parent[s] = s;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(visit[v]==false)
            {
                visit[v] = true;
                q.push(v);
                parent[v] = u;
                if(v==d)    break;
            }
        }
        if(visit[d]==true)  break;
    }
    int p = d;

    while(true)
    {
        path.push_back(p);
        if(p==parent[p])    break;
        p = parent[p];
    }
    reverse(path.begin(),path.end());
    cout<<path[0];
    for(int i=1;i<path.size();i++)
        cout<<" "<<path[i];
    cout<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        vector<int>cities(n);
        path.clear();
        for(int i=1;i<=50000;i++)
            adj[i].clear();

        for(int i=0;i<n;i++)
            cin>>cities[i];

        for(int i=0;i<n-1;i++)
        {
            int u = cities[i];
            int v = cities[i+1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++)
            sort(adj[cities[i]].begin(),adj[cities[i]].end());

        printf("Case %d:\n",k);
        BFS(cities[0],cities[n-1]);
        cities.clear();
    }
    return 0;
}
