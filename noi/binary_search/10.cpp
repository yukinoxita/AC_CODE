#include <cstdio>
int L,n,m;
int a[50020];
void find()
{
    int l,r,mid;
    l = 1,r = L+1;
    register int i;
    a[0] = 0;
    int pre = a[0];//前置点
    int cnt = 0;//当答案等于mid时需要移除石头的个数
    while(l != r)
    {
        cnt = 0;
        pre = a[0];
        mid = (l+r)>>1;
        for(i=1;i<=n;i++)
        {
            if(a[i] - pre < mid)cnt++;
            else
                pre  = a[i];
        }
        if(L - pre < mid)cnt++;
        if(cnt > m)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d",l-1);
}
int main()
{
    register int i;
    freopen("1.in","r",stdin);
    scanf("%d%d%d",&L,&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    find();
    return  0;
}