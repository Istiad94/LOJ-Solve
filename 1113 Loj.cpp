#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    sif(t);
    getc(stdin);

    for(int cn=1;cn<=t;cn++)
    {
        stack<string>f,b;
        string s;

        b.push("http://www.lightoj.com/");
        pf("Case %d:\n",cn);

        while(1)
        {
            get_stl(s);

            if(s[0]=='Q')   break;

            if(s[0]=='V')
            {
                string t;

                for(int i=6;s[i]!=0;i++)
                    t += s[i];

                pf("%s\n", t.c_str());

                b.push(t);

                while(f.size()!=0)
                    f.pop();

                continue;
            }

            else if(s[0]=='B')
            {
                if(b.size()<=1)
                {
                    pf("Ignored\n");
                    continue;
                }

                else
                {
                    f.push(b.top());
                    b.pop();
                    pf("%s\n", b.top().c_str());
                    continue;
                }

            }

            else if(s[0]=='F')
            {
                if(f.size()==0)
                {
                    pf("Ignored\n");
                    continue;
                }
                else
                {
                    pf("%s\n", f.top().c_str());
                    b.push(f.top());
                    f.pop();
                    continue;
                }
            }
        }
    }
    return 0;
}
