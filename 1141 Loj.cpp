#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;


int mark[1000];
vector<int>prime;

void sieve(int range = 1000)
{
    for(int i=2;i<range;i++)
    {
        if(!mark[i])
        {
            mark[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<range&&prime[j]<=i;j++)
            mark[i*prime[j]]=prime[j];
    }
}

int level[10000];
bool visit[10000];

void BFS(int s,int t)
{
    level[s] = 0;
    if(s==t)
    {
        cout<<level[s]<<endl;
        return;
    }
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<prime.size()&&prime[i]<u;i++)
        {
            if(u%prime[i]==0)
            {
                int v = u + prime[i];
                if(v<=t&&visit[v]==false)
                {
                    visit[v] = true;
                    level[v] = 1 + level[u];
                    q.push(v);
                    if(v==t)    break;
                }
            }
        }
        if(visit[t]==true)
        {
            cout<<level[t]<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    int test;
    cin>>test;
    for(int k=1;k<=test;k++)
    {
        int s,t;
        cin>>s>>t;
        printf("Case %d: ",k);
        BFS(s,t);
    }
    return 0;
}
