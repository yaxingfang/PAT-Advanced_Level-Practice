## 1065 A+B and C (64bit) （20 分）

Given three integers *A*, *B* and *C* in [−263,263], you are supposed to tell whether *A*+*B*>*C*.

### Input Specification:

The first line of the input gives the positive number of test cases, *T* (≤10). Then *T* test cases follow, each consists of a single line containing three integers *A*, *B*and *C*, separated by single spaces.

### Output Specification:

For each test case, output in one line `Case #X: true` if *A*+*B*>*C*, or `Case #X: false` otherwise, where *X* is the case number (starting from 1).

### Sample Input:

```in
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```

### Sample Output:

```out
Case #1: false
Case #2: true
Case #3: false
```

### Code

```c++
#include <cstdio>
int main () {
	int n;
	long long a, b, c;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld %lld %lld", &a, &b, &c);
		printf ("Case #%d: ", i);
		long long sum = a + b;
		if ((a > 0 && b > 0 && sum < 0)) {
			printf ("true\n");	//正溢出：超出long long范围，又是俩正数那自然比c大 
		} else if (a < 0 && b < 0 && sum >= 0) {
			printf ("false\n");	//负溢出：超出long long范围，又是俩负数，自然比c小 
		} else if (sum <= c) {	//下面无溢出正常判断 
			printf ("false\n");
		} else {
			printf ("true\n");
		}
	}
	return 0;
}
```

