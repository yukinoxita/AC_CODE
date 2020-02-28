#include <iostream>
#include <cstdio>
using namespace std;
/*
这个题解不是我写的
author: zxx
from: 湖北汽车工业学院    registered on 2019-12-28

实在不想写这个捞B题目了，我一晚上想他没睡着觉
*/
int main(){
	int n;
	//打表
	int a[12]={0,0,1,2};
	long long b[12]={1,1,2,6};
	double ans[12]={0};
	for(int i=4;i<12;i++)
	{
		a[i]=(i-1)*(a[i-1]+a[i-2]);
		b[i]=b[i-1]*i;
		ans[i]=a[i]*100.0/b[i];
	}
	ans[1]=a[1]*100.0/b[1];
	ans[2]=a[2]*100.0/b[2];
	ans[3]=a[3]*100.0/b[3];
	while(cin>>n)
	{
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp<8)
			{
				printf("%.2f%%\n",ans[temp]);
			}
			else
			{
				printf("36.79%%\n");
			}
		}
	}
	return 0;
}