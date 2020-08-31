#include <cstdio>
#include <cstring>
int a[10001];
int f[10001]={1};
int n,m,T;
int maxx(int x,int y)
{
    if(x>y)return x;
    return y;
}
void dp(int l,int r)
{
    int i,j;
    for(i=l-2;i<=r+2;i++)f[i]=1;
    for(i=l;i<=r;i++)
    {
        for(j=1;j<i;j++)
        {
            if(a[j]<a[i])
                f[i]=maxx(f[i],f[j]+1);
            else
                f[i]=maxx(f[i],f[j]);//不加这句话就是以i为结尾的LIS
        }
    }
}
void iint()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);f[i]=1;}
}
int main()
{
    int i;
    //freopen("2.in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        iint();
        for(i=1;i<=m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            dp(l,r);
            printf("%d",f[r]);
            if(i!=m)printf(" ");
        }
        if(T)printf("\n");
    }
    return 0;
}
