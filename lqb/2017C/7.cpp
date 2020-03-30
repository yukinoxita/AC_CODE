#include<iostream>
using namespace std;
int main()
{
    //可将这道题视为26进制转换，但是，当余数为零时，余数应该为26 
    long long int n,m;
    int a[100]; // 存放每一轮的余数 

    while(cin>>n)
    {
        int i = 0;
        while(n)
        {
            m = n % 26;// 取余 
            if(m == 0)
            {
                m = 26;	//余数为零，置为26，代表‘Z ’ 
            }	
            n = (n - m) / 26;  
            a[i++] = m;	 //把余数逐步放入数组 
        }
        for(int j = i - 1;j >= 0;j--)//倒序输出 
        {
            cout<<char ('A' + a[j] - 1);
        }		 
    } 
    return 0;
}
