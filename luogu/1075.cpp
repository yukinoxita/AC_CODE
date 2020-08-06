/*
Author  : yukki
Time    : 2020.8.1
OJ      : luogu
Pid     : 1075
 */
#include <cstdio>
#include <cmath>
#define scnaf scanf
/*
注意
从2-n/ans比从n到ans更快
*/
int n;
bool is_prime(int num)
{
    register int i;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)return false;
    }
    return true;
}
int main()
{
    register int i,j;
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++)
    {
        if(i!=2 && i%2==0)continue;
        if(n%i != 0)continue;
        if(is_prime(i)){printf("%d\n",n/i);break;}
    }
	return 0;
}

