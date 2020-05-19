#include <cstdio>
#include <cstring>
#define maxn 10001
int n;
int a[maxn];
int b[maxn];
int cnt;
void merge(int l,int mid,int r)
{
    int ll = l;
    int rr = mid+1;
    int sit = l-1;
    while(1)
    {
        if(ll > mid && rr > r)break;
        if(a[ll]<a[rr])
        {
            if(ll<=mid)
                b[++sit] = a[ll++];
            else
                b[++sit] = a[rr++];
        }
        else
        {
            if(rr<=r)
            {
                cnt += mid-ll+1;
                //在归并排序基础上加上
                //这句话表示后面的数字
                //都比这个数字大都可以
                //形成逆序对
                b[++sit] = a[rr++];
            }
            else
                b[++sit] = a[ll++];
        }
    }
    int i;
    for(i=l;i<=r;i++)a[i] = b[i];
}
void mergesort(int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)>>1;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
}
int main()
{
    register int i;
    //freopen("1.in","r",stdin);
    scanf("%d", &n);
    for(i=1;i<=n;i++)scanf("%d", &a[i]);
    mergesort(1,n);
    printf("%d",cnt);
    return 0;
}
