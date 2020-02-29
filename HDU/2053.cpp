#include <cstdio>
#include <cmath>
/*
思路:
    寻找n的所有因数，个数为单数就为1，双数为0
优化:
    搜索sqrt(n),得到的结果*2

*/
int n;
int main()
{
    int i;
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    while(scanf("%d",&n) != EOF)
    {
        if(n == 1){printf("1\n");continue;}
        int cnt = 2;
        /*
            sqrt 函数原型是 double，
            所以他会返回一个double类型的参数，
            一定要转换成int在这里
        */
        if((int)sqrt(n) * (int)sqrt(n) == n)cnt--;
        for(i=2;i<=sqrt(n);i++)
            if(n % i == 0)cnt += 2;
        if(cnt % 2 == 0)printf("0\n");
        else printf("1\n");
    }
    return 0;
}
/*
时间对比
TIME    MEM
0MS	    1740K
93MS    1736k
*/