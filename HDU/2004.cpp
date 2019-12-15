#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int r;
int main()
{
    int i;
 //   freopen("2.in","r",stdin);
    while(scanf("%d",&r)!=EOF)
    {
        if(r>=90 && r<=100)printf("A\n");
        else if(r>=80 && r<90)printf("B\n");
        else if(r>=70 && r<80)printf("C\n");
        else if(r>=60 && r<70)printf("D\n");
        else if(r>=0 && r<60)printf("E\n");
        else printf("Score is error!\n");
    }
    return 0;
}