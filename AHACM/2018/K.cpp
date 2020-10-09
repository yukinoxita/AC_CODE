#include<cstdio>
int t;
long long int  n; 
/*
首先，我们需要知道一个定理：一切大于2的质数，一定是形如4n+1或4n-1的数。

由于我们每次给的数可以是1，2，3+（大于2的）质数。那么无论谁先讲，后手的一定可以加成4n。所以说，只要给的数能够被4整除，Bob必胜。反之，Alice必胜。
*/
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%4==0)
			printf("Bob win\n");
		else 
		    printf("Alice win\n");
	}
	return 0;
}
