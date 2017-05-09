
#include<bits/stdc++.h>

using namespace std;
int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);
    vector<int>array;
    string o;
    int j,test,n,i,v,no;
    cin>>test;
    for(j=1;j<=test;j++)
    {
        printf("Case %d:\n", j);
        cin>>n>>no;
        for(i=0;i<n;i++)
        {
            cin>>v;
            array.push_back(v);
        }
        while(no--)
        {
            cin>>o;
            if(o=="S")
            {
                int d;
                cin>>d;
                for(i=0;i<n;i++)
                    array[i]+=d;
            }
            else if(o=="M")
            {
                int m;
                cin>>m;
                for(i=0;i<n;i++)
                    array[i]*=m;
            }
            else if(o=="D")
            {
                int k;
                cin>>k;
                for(i=0;i<n;i++)
                    array[i]/=k;
            }
            else if(o=="R")
            {
                reverse(array.begin(), array.end());
            }
            else if(o=="P")
            {
                int x,y;
                cin>>x>>y;
                swap(array[x],array[y]);
            }
        }
        for(i=0;i<n;i++)
        {
            cout<<array[i];
            if(i!=n-1)
                cout<<" ";
            else
            cout<<endl;
        }
        array.clear();
    }
    return 0;
}
