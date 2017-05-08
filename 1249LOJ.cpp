#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

int main()
{
    //freopen("d:\\test.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);

    int test, i;
    cin>>test;

    for(i=1;i<=test;i++)
    {
        int j,n,h,w,l;
        cin>>n;
        int max, min;
        string name, thief, victim;
        for(j=0;j<n;j++)
        {
            cin>>name>>h>>w>>l;
            int area=h*w*l;
            if(j==0)
            {
                max=area;
                thief=name;
                min=area;
                victim=name;
                continue;
            }
            if(max<area)
            {
                max=area;
                thief=name;
            }
            if(min>area)
            {
                min=area;
                victim=name;
            }
        }
        if(max==min)
            printf("Case %d: no thief\n", i);
        else
            cout<<"Case "<<i<<": "<<thief<<" took chocolate from "<<victim<<endl;
    }

    return 0;
}
