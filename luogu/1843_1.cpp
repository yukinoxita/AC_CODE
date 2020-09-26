/*
Author  : yukki
Time    : 2020.9.25
OJ      : luogu
Pid     : 1843
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,a,b;
int t;
int heap[500050];
int len;
void up(int p)
{
    int pos = p;
    while(pos >> 1)
    {
        if(heap[pos>>1] < heap[pos])
        {
            int tmp;
            tmp = heap[pos];
            heap[pos] = heap[pos>>1];
            heap[pos>>1] = tmp;
            pos = pos>>1;
        }
        else break;
    }
}
void down(int p)
{
    int pos = p;
    while(pos<<1 <= len)
    {
        int tmp = pos<<1;
        if(tmp + 1 <= len && heap[tmp] < heap[tmp+1])tmp++;
        if(heap[pos] < heap[tmp])
        {
            int temp;
            temp = heap[pos];
            heap[pos] = heap[tmp];
            heap[tmp] = temp;
            pos = tmp;
        }
        else break;
    }
}
void push(int num)
{
    heap[++len] = num;
    up(len);
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    len = 0;
    F1(i,n)
    {
        int tmp;
        scanf("%d",&tmp);
        push(tmp);
    }
    int times = 0;
    while(heap[1] > times * a)
    {
        times++;
        heap[1] -= b;
        down(1);
    }
    printf("%d\n",times);
    return 0;
}
