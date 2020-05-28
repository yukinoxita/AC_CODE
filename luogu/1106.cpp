#include <cstdio>
#include <cstring>
/*
 *author : rainboy
 *ps     : 懒得写了，运行一遍后看懂了就直接提交了
 * */
char s[300]; //数字
int k;//要删除几位

int main()
{
    freopen("1.in", "r", stdin);
    scanf("%s",s);

    scanf("%d",&k);

    int cnt;
    int i,j;
    for(cnt  =1;cnt <=k;cnt++){
        int len = strlen(s);
        for(i=0;i<len;i++){
            if(s[i] > s[i+1]){
                for(j=i;j<len;j++)s[j] =s[j+1]; //往前移
                break;
            }
        }
    }

    int len = strlen(s);
    int first_not_zero;
    for(i=0;i<len;i++){
        if( s[i] !='0'){
            first_not_zero = i;
            break;
        }
    }
    if( i == len) 
        printf("0");
    else 
        printf("%s",&s[first_not_zero]);
    return 0;
}
