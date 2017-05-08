#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int test, i;
    cin>>test;

    for(i=1;i<=test;i++)
    {
        printf("Case %d:\n",i);
        int op,sum=0,money;
        char str[10];
        cin>>op;
        while(op--)
        {
            scanf("%s",str);
            if(str[0]=='d')
            {
                cin>>money;
                sum+=money;
            }
            else
                cout<<sum<<endl;
        }
    }
    return 0;
}
