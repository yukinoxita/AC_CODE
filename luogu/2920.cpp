/*
Author  : yukki
Time    : 2020.9.25
OJ      : luogu
Pid     : 2920
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
struct node
{
    int start,ends;
};
vector <node> vec;
int n,m;
int ans;
bool cmp(const node & a,const node & b){return a.ends<b.ends;}
bool check(int mid)
{
    int cnt = mid;
    int i;
    vector <node>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
    {
        node t = *it;
        if(cnt+t.start<=t.ends){cnt+=t.start;continue;}
        else return 0;
    }
    return 1;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    F1(i,n)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end(),cmp);
    vector <node>::iterator it;
    int l = 1;
    int r = 10000000;
    while(l<r)
    {
        int mid = (l+r)>>1;
        //printf("l = %d r = %d mid = %d\n",l,r,mid);
        //sleep(1);
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;

    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<-1;
    /*
    for(it=vec.begin();it!=vec.end();it++)
    {
        node t =*it;
        cout<<t.start<<" "<<t.ends<<endl;
    }
    */
    return 0;
}

