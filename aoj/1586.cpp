/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1586
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
//next_permutation
int n,m;
int a[10];
int main()
{
    register int i,j;
    scanf("%d",&n);
    F1(i,n)a[i] = i;

    F1(i,n)printf("%d",a[i]);
    printf("\n");
    while(next_permutation(a+1,a+1+n))
    {
        F1(i,n)printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}

