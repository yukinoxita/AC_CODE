#include <cstdio>
#include <cstring>
double a[32][32];
/*
    这一题坑在什么地方？
    答案是按比例算的，
    数组开double，因为
    要除以2,会有小数。
*/
int main()
{
    int i,j;
    double tmp;
    int cnm = 2086458231;//给我气毁了
    freopen("1.in","r",stdin);
    for(i=1;i<=29;i++)
    {
        for(j=1;j<=i;j++)
        {
            scanf("%lf",&tmp);
            a[i][j] += tmp;
            a[i+1][j]   += a[i][j]/2;
            a[i+1][j+1] += a[i][j]/2;
        }
    }
    double max = 0;
    double min = 21474847;
    int max_index;
    int min_index;
    for(i=1;i<=30;i++)
    {
        if(max < a[30][i]){max = a[30][i];max_index = i;}
        if(min > a[30][i]){min = a[30][i];min_index = i;}
    }
    printf("%.0lf",(max*cnm/min));
    return 0;    
}