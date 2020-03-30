#include <cstdio>
#include <cstring>
char letter;
int num;
int n;
int power[26];
int lower[26];
int main()
{
    int i;
    freopen("1.in","r",stdin);
    power[0] = 1;
    lower[0] = -1;
    for(i=1;i<26;i++)
    {
        power[i] = power[i-1] + 1;
        lower[i] = lower[i-1] - 1;
    }
    scanf("%d",&n);
    while(n--)
    {
        getchar();//注意一下
        scanf("%c %d",&letter,&num);
        if(letter >='A' && letter <='Z')
            printf("%d\n",power[letter-'A'] + num);
        else
            printf("%d\n",lower[letter-'a'] + num);
    }
    return 0;
}