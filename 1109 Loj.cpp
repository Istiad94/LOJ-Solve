#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)
 
using namespace std;
typedef long long ll;
 
vector<pii>nums;
 
void factorize(int n)
{
    int temp = n;
    int root = sqrt(n);
    int ans = 1;
    for(int i=2;i<=root;i++)
    {
        if(n%i==0)
        {
            int c = 0;
            while(n%i==0)
            {
                n/=i;
                c++;
            }
            ans*=(c+1);
        }
    }
    if(n>1) ans*=2;
    nums.push_back({temp,ans});
}
bool comp(pii a,pii b)
{
    if(a.second!=b.second)
        return a.second < b.second;
    return a.first > b.first;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 
    for(int i=1;i<=1000;i++)
        factorize(i);
    sort(nums.begin(),nums.end(),comp);
 
    int test,id;
    cin>>test;
 
    for(int k=1;k<=test;k++)
    {
        cin>>id;
        printf("Case %d: %d\n",k,nums[--id].first);
    }
 
    return 0;
}
