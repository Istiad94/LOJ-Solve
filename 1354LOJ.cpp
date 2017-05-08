#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
using namespace std;

void bins(int n, char binset[])
{
    char bin[8];
    int j,m;
    for(j=7;j>=0;j--)
    {
        m=n%2;
        if(m==1)
            binset[j]='1';
        else
            binset[j]='0';
        n/=2;
    }
    binset[8]='\0';
}
void copy(char str[], char a[], char b[], char c[], char d[])
{
    int i,j;
    for(i=0;i<8;i++)
        a[i]=str[i];
        a[8]='\0';
    for(j=0,i=9;j<8;j++,i++)
        b[j]=str[i];
        b[j]='\0';
    for(j=0,i=18;j<8;i++,j++)
        c[j]=str[i];
        c[j]='\0';
    for(j=0,i=27;j<8;i++,j++)
        d[j]=str[i];
        d[j]='\0';
}
int main()
{
    //freopen("d:\\test.txt", "r", stdin);
    int i,j;
    char binset [256][256];
    for(i=0;i<256;i++)
        bins(i, binset[i]);
    int test;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        int n1,n2,n3,n4;
        scanf("%d.%d.%d.%d", &n1,&n2,&n3,&n4);
        char a[80],b[80],c[80],d[80],str[1000];
        scanf("%s",str);
        copy(str, a,b,c,d);
        if(!strcmp(binset[n1],a)&&!strcmp(binset[n2],b)&&!strcmp(binset[n3],c)&&!strcmp(binset[n4],d))
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}
