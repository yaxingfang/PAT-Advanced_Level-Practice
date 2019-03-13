## 1049 Counting Ones （30 分)

The task is simple: given any positive integer *N*, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to *N*. For example, given *N* being 12, there are five 1's in 1, 10, 11, and 12.

### Input Specification:

Each input file contains one test case which gives the positive *N* (≤230).

### Output Specification:

For each test case, print the number of 1's in one line.

### Sample Input:

```in
12
```

### Sample Output:

```out
5
```

### Code

```c++
/*对n的每一位，记录该位为1的总次数累加
该位为now, left为该位左边的数，right为该位右边的数，a控制当前位位哪一位，初始为1表示当前位位个位
对于now有三种情况：
now = 0: 此时now位要求是1，那么left只能取 0 ~ left - 1,如果取left那就直接超出n了，
由now的高位取的小，那么now的低位随便取，毕竟高位已经定大小了right取 0 ~ a - 1 
now == 1: 此时除去上面的情况，还有left可以取到left, 而对应right能取到 0 ~ right 
now >= 2: 由于now位取1是小于当前位的，所以剩余位随便取left取到 0 ~ left，right取到 0 ~ a - 1 
*/ 
#include <cstdio>
int main () {
	int n, a = 1, ans = 0;
	int now, left, right;
	scanf ("%d", &n);
	while (n/a != 0) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10; 
	}
	printf ("%d\n", ans);
	return 0;
}
```

