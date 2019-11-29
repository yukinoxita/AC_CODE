#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[2010];
int n;
int ans;
long long int k;
void res()
{
    int i;
    for(i=n;i>=1;i--)printf("%d",a[i]);
    cout<<endl;
    ans++;
}
bool check()
{
    int num = 0;
    for(int i=1;i<=6;i++)if(a[i] == 1)num++;
    if(num == 3)return true;
    return false;
}
bool low()
{
    int i;
    int num0 = 0;
    int num1 = 0;
    for(i=n;i>=1;i--)
    {
        if(a[i] == 1)num1++;        
        if(a[i] == 0)num0++;
        if(i % 2 == 1 && num0 <  num1)return false;
        if(i % 2 == 0 && num0 <= num1)return false;
    }
    if(num0 != num1)return false;
    return true;
}
void out()
{
    int i;
    for(i=n;i>=1;i--)
    {
        if(a[i] == 1)printf(")");
        if(a[i] == 0)printf("(");
    }
}
int main()
{
    int i;
    scanf("%d%d", &n,&k);
    while(a[n]<1)
    {
        a[1]++;
        for(i=1;i<=n;i++)
        {
            if(a[i] == 2)
            {
                a[i] = 0;
                a[i+1] += 1;
                if(a[n+1] != 0)break;
            }
        }
        if(a[n+1] != 0)break;
        if(a[n+1] == 0 && low())//res();
        {
            ans++;
            if(k == ans)
            {
                out();
                break;
            }
        }
    }
    //printf("cnt = %d",ans);
    return 0;
}
/*
Author : yukinoxita
Time :2019-11-28
which : https://oj.ahstu.cc/problem.php?cid=1355&pid=6&langmask=0&puzzle_mask=0
PS : to test git command
*/