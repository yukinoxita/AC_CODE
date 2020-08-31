#include <cstdio>
#include <iostream>
using namespace std;
int t,l,r;
int ans=0;
void chu(int num)
{
    while(num>0)
    {
        if(num%7!=0)return ;
        if(num%7==0){ans++;num/=10;}
    }
}
void have(int num)
{
    while(num>0)
    {
        if(num%10==7)ans++;
        num/=10;
    }
}
void find()
{
    int i;
    for(i=l;i<=r;i++)
    {
        if(i%7==0){ans++;chu(i/7);}
        have(i);
    }
}
int main()
{
    int i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&l,&r);
        find();
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
