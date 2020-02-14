#include <cstdio>
#include <cmath>
int n;
int a[42];
int sit = 3;//记录当前算到的答案的最高点
void keisan(int num)
{
    int i;
    for(i=sit+1;i<=num;i++)a[i] = a[i-1] + a[i-2];
}
int main()
{
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    while (n--)
    {
        int tmp;
        scanf("%d",&tmp);
        if(a[tmp] != 0)printf("%d\n",a[tmp]);//存在就输出
        else 
        {
            keisan(tmp);
            sit = tmp;
            printf("%d\n",a[tmp]);
        }
    }
    return 0;
}
