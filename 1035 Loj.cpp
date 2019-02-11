#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int freq[100];

void fact(int N)
{
    memset(freq,0,sizeof(freq));
    for(int i=2;i<=N;i++)
    {
        int n=i;
        for(int j=2;j*j<=n;j++)
        {
            if(n%j==0)
            {
                while(n%j==0)
                {
                    freq[j]++;
                    n/=j;
                }
            }
        }
        if(n>1)
            freq[n]++;
    }

    bool first = true;

    for(int i=2;i<=97;i++)
    {
        if(freq[i])
        {
            if(first)
            {
                printf(" = %d (%d)",i,freq[i]);
                first=false;
            }
            else
                printf(" * %d (%d)",i,freq[i]);
        }
    }

    puts("");

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,n;
    cin>>test;

    for(int kase=1;kase<=test;kase++)
    {
        cin>>n;
        printf("Case %d: %d",kase,n);
        fact(n);
    }
    return 0;
}
