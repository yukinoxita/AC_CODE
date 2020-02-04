#include <cstdio>
int a[10010];
int n;
int ans;
int sit = 1;
/*
思路:
    将不在位子上的瓶子放回属于他的位子上
    将此本来放在那个位置上的瓶子放到空出来的位置
    即交换瓶子
*/
int main()
{
    int i;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(sit != n)
    {

        if(a[sit] == sit){sit++;continue;}//本来就在就不用操作了
        else
        {
            int tmp;
        /*
            3 2 1 4 5
            1 2 3 4 5
        */
            ans++;
            tmp = a[a[sit]];
            a[a[sit]] = a[sit];
            a[sit] = tmp;
        }
    }
    printf("%d",ans);
    return 0;
}