#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,r;
int bit[100];
char alpha[6]={'A','B','C','D','E','F'};
int sit;
bool flag;
/*
dec turn to other 2<=x<=16 && x!=10

int only need 32bit  2**32-1
*/
void print()
{
    int i;
    if(flag)printf("-");
    for(i=sit;i>=1;i--)
    {
        if(bit[i]<10)printf("%d",bit[i]);
        else printf("%c",alpha[bit[i]%10]);
    }
}
void kenkan()
{
    int num = n;
    sit = 0 ;
    while(num)
    {
        bit[++sit] = num % r;
        num /= r;
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&r);
    kenkan();
    print();
    return 0;
}