/*
Author  : yukki
Time    : 2020.8.6
OJ      : luogu
Pid     : 2669
 */
#include <cstdio>

#define scnaf scanf
int k;
int a[150];//a[i]表示第i层为多少
int f[150];//f[i]表示第i层的答案是多少
/*
ans = k所到达的前一层的答案+本层多余的答案

*/
int find1()
{
    /*暴力寻找*/
    register int i;
    for(i=1;;i++)
    {
        if(a[i] > k)return i-1;
    }
}
int find2()
{
    /*数据大的时候可以二分*/
    /*这题数据不大无所谓了*/
    //寻找第一个大于k的下标
    int l=1,r=142;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(a[mid] > k)
            r = mid;
        else
            l = mid+1;
    }
    /*答案应该是l-1,因为如果
    最后一次的结果是a[mid]<=k
    那么l是要等于mid+1的，所以
    应该返回l-1
    */
    return l-1;
}
int main()
{
    register int i,j;
    scanf("%d",&k);
    for(i=1;i<=141;i++)a[i] = ((i+1)*i)/2;
    int line = find2();
    int ans = 0;
    f[1] = 1;
    for(i=2;i<=line;i++)f[i] = f[i-1] + i * i;
    ans = f[line] + (k-a[line])*(line+1);
    printf("%d\n",ans);
	return 0;
}

