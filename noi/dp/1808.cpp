#include <cstdio>
#include <cstring>
int f[202][202];
char a[202],b[202];
int max(int x,int y){return x>y?x:y;}
int main()
{
    register int i ,j;
    while(scanf("%s%s",a+1,b+1) != EOF)
    {
        //printf("%s %s\n",a+1,b+1);
        memset(f,0,sizeof(f));
        int len1 = strlen(a+1);
        int len2 = strlen(b+1);        
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(a[i] == b[j])
                    f[i][j] = f[i-1][j-1] + 1;
                else
                    f[i][j] = max(f[i-1][j],f[i][j-1]);

            }
        }
        printf("%d\n",f[len1][len2]);
    }
    return 0;
}