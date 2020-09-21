/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1588
*/
#include <cstdio>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
/*
    1000*1000都能过
    老子失去耐心了
    也不想算极限了
    2000*2000循环
*/
int n,m;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int ans = 0;
int sum(int num)
{
    int cnt = 0;
    while(num >= 10)
    {
        cnt += a[num%10];
        num /= 10;
    }
    return cnt+a[num];
}
int main()
{
    register int i,j;
    scanf("%d",&n);
    F0(i,2000)
    {
        F0(j,2000)
        {
            int cnt = 0;
            cnt += sum(i);
            cnt += sum(j);
            cnt += sum(i+j);
            if(cnt + 4 == n)ans++;
        }
    }
    printf("%d\n",ans);
   // printf("sum(10) = %d\n",sum(10));
    return 0;
}

