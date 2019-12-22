#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int p[55][6];
double avg_point[6];
/*
算法：模拟
思路:
    直接模拟就行了
    你也可以分成三
    个步骤创建函数
    去计算。
    注意平均的时候
    除的是哪个就行了
*/
void find_ans()
{
    int i,j;
    double ans = 0;
    int cnt = 0;//记录大于平均成绩的学生
    //求学生平均成绩
    for(i=1;i<=n;i++)
    {
        ans = 0;
        for(j=1;j<=m;j++){ans += p[i][j];avg_point[j] += p[i][j];}//在求学生的时候顺便计算每门课的总成绩
        printf("%.2lf",ans/m);
        if(i != n){printf(" ");}
    }
    printf("\n");
    //求每门课平均成绩
    for(i=1;i<=m;i++){avg_point[i] /= n;printf("%.2lf",avg_point[i]);if(i != m)printf(" ");}//总成绩除以总人数
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(p[i][j] < avg_point[j])break;
            if(j == m)cnt++;
        }
    }   
    printf("%d\n",cnt);
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int ans = 0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)scanf("%d",&p[i][j]);
        find_ans();
        printf("\n");
        memset(p,0,sizeof(p));
        memset(avg_point,0,sizeof(avg_point));
    }
    return 0;
}