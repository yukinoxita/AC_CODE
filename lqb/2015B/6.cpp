#include <cstdio>
int n = 1225;
int m = 2015;
int main()
{
    int i,j;
    int tmp = n;
    for(i=1;i<49;i++)
    {
        for(j=i+2;j<49;j++)
        {
            tmp = n;
	    //加法换乘法
            tmp -= (i+i+1+j+j+1);
            tmp += (i*i+i+j*j+j);
            if(tmp == m)printf("%d\n",i);
                      
        }
    }
    return 0;
}
