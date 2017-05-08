#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("d:\\test.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);
    unsigned long long test, i;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        unsigned long long n, m, j, sum=0;
        cin>>n>>m;
        sum=(n*m)/2;
        printf("Case %llu: %llu\n", i,sum);
    }
    return 0;
}

