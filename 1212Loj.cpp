#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n", i);
        int n, m, d, s=0;
        cin>>n>>m;
        deque<int>q;
        string c;
        while(m--)
        {
            cin>>c;
            if(c[3]=='h')///Push function Started
            {
                cin>>d;
                if(c[4]=='L')
                {
                    if(s<n)
                    {
                        cout<<"Pushed in left: "<<d<<endl;
                        q.push_front(d);
                        s++;
                    }
                    else if(s==n)
                    {
                        cout<<"The queue is full\n";
                        continue;
                    }
                }

                else if(c[4]=='R')
                {
                    if(s<n)
                    {
                        cout<<"Pushed in right: "<<d<<endl;
                        q.push_back(d);
                        s++;
                    }
                    else if(s==n)
                    {
                        cout<<"The queue is full\n";
                        continue;
                    }
                }

            }///Push function Ended

            else if(c[2]=='p')///Pop start
            {
                if(c[3]=='L')
                {
                    if(s>0)
                    {
                        cout<<"Popped from left: "<<q[0]<<endl;
                        q.pop_front();
                        s--;
                    }
                    else if(s==0)
                    {
                        cout<<"The queue is empty\n";
                        continue;
                    }
                }

                else if(c[3]=='R')
                {
                    if(s>0)
                    {
                        cout<<"Popped from right: "<<q[s-1]<<endl;
                        q.pop_back();
                        s--;
                    }
                    else if(s==0)
                    {
                        cout<<"The queue is empty\n";
                        continue;
                    }
                }

            }///Pop Function Ended
        }
    }
    return 0;
}
