## 1096 Consecutive Factors （20 分)

Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

### Input Specification:

Each input file contains one test case, which gives the integer N (1<N<231).

### Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format `factor[1]*factor[2]*...*factor[k]`, where the factors are listed in increasing order, and 1 is NOT included.

### Sample Input:

```in
630
```

### Sample Output:

```out
3
5*6*7
```

### Code

```c++
#include<cstdio>
#include<cmath>
bool prime(int num)
{
	if(num==2) return true;
	int i,n=sqrt(num);
	for(i=2;i<=n;i++) {
		if(num%i==0) return false;
	}
	return true;
}
int main()
{
	int t,n,m,i,j,s,len;
	scanf("%d",&n);
	m=sqrt(n);
	if(prime(n)) printf("1\n%d\n",n);
	else {
		s=0;len=0;
		for(i=2;i<=m;i++) {
			t=1;
			for(j=0;j<=m;j++) {
				t*=(i+j);
				if(n%t) break;
			}
			if(j>len) {
				len=j;
				s=i;
			}
		}
		printf("%d\n",len);
		for(i=s;i<s+len;i++) {
			if(i!=s) printf("*");
			printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}
 
 
```

