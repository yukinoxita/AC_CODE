#include <cstdio>
int a[100010];
int b[100010];
int n,k;
int minn = 0;
bool check(int num)
{
    int i,j;
    int cnt = 0;
    for(i=1;i<=n;i++)
    {
        cnt += ((a[i]/num)*(b[i]/num));
        if(cnt >= k)return true;
    }
   // printf("num = %d, cnt = %d\n",num,cnt);
    return 0;
}
int main()
{
    int i,j;
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){scanf("%d%d",&a[i],&b[i]);if(minn < b[i])minn = b[i];if(minn < a[i])minn = a[i];}
    while(1)
    {
        if(check(minn)){printf("%d",minn);break;}
        minn -- ;
    }
    return 0;
}