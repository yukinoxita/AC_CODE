#include <cstdio>
int n;
bool flag = 0;
int main()
{
    int a,b,c,d;
    scanf("%d",&n);
    for(a=0;a<=2237;a++)
    {
        int muli1 = a*a;
        if(muli1 > n || flag)break;
        for(b=0;b<=2237;b++)
        {
            int muli2 = muli1 + b*b;
            if(muli2 > n || flag)break;
            for(c=0;c<=2237;c++)
            {
                int muli3 = muli2 + c*c;
                if(muli3 > n || flag)break;
                for(d=0;d<=2237;d++)
                {
                    int muli4 = muli3 + d*d;
                    if(muli4 > n || flag)break;
                    if(muli4 == n)
                    {
                        printf("%d %d %d %d",a,b,c,d);
                        flag = 1;
                    }
                }
            }
        }
    }
    return 0;
}