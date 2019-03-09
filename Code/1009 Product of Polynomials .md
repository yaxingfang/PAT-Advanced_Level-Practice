## 1009 Product of Polynomials （25 分）

This time, you are supposed to find *A*×*B* where *A* and *B* are two polynomials.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

*K* *N*1 *a**N*1 *N*2 *a**N*2 ... *N**K* *a**N**K*

where *K* is the number of nonzero terms in the polynomial, *N**i* and *a**N**i* (*i*=1,2,⋯,*K*) are the exponents and coefficients, respectively. It is given that 1≤*K*≤10, 0≤*N**K*<⋯<*N*2<*N*1≤1000.

### Output Specification:

For each test case you should output the product of *A* and *B* in one line, with the same format as the input. Notice that there must be **NO** extra space at the end of each line. Please be accurate up to 1 decimal place.

### Sample Input:

```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:

```out
3 3 3.6 2 6.0 1 1.6
```

### Code

```c++
#include <iostream>
using namespace std;
int main () {
	int n, m, a, cnt = 0;
	double b, A[1001] = {0}, B[1001] = {0}, ans[2001] = {0};
	//分别存储第一行，第二行，以及乘后的结果 
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %lf", &a, &b);
		A[a] += b;
	}
	scanf ("%d", &m);
	while (m--) {
		scanf ("%d %lf", &a, &b);
		B[a] += b;
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			ans[i + j] += A[i] * B[j];
		}
	}
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0) {
			cnt++;
		}
	}
	printf ("%d", cnt);
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0) {
			printf (" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}
```

