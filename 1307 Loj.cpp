#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    int t,n,x;
    vector<int>s;
 
    cin>>t;
 
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            s.push_back(x);
        }
        sort(s.begin(),s.end());
        int c = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int r = upper_bound(s.begin()+j+1,s.end(),s[i]+s[j]-1) -
                        lower_bound(s.begin()+j+1,s.end(),s[j]);
                c+=r;
            }
        cout<<"Case "<<k<<": "<<c<<endl;
        s.clear();
    }
    return 0;
}
