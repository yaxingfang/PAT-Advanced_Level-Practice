## 1015 Reversible Primes （20 分)

A **reversible prime** in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers *N* (<105) and *D* (1<*D*≤10), you are supposed to tell if *N* is a reversible prime with radix *D*.

### Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers *N* and *D*. The input is finished by a negative *N*.

### Output Specification:

For each test case, print in one line `Yes` if *N* is a reversible prime with radix *D*, or `No` if not.

### Sample Input:

```in
73 10
23 2
23 10
-2
```

### Sample Output:

```out
Yes
Yes
No
```

### Code

```c++
/*涉及素数的判断，十进制与Q进制的互相转化*/
#include <cstdio>
#include <cmath> 
bool isPrime (int x) {
	if (x <= 1) return false;
	else {
		int sqr = (int)sqrt(1.0 * x);
		for (int i = 2; i <= sqr; i++) {
			if (x % i == 0) return false;
		}
	}
	return true;
}
int main () {
	int n, d;
	while (scanf ("%d", &n) != EOF) {
		if (n < 0) break;
		scanf ("%d", &d);
		if (isPrime(n) == false) {
			printf ("No\n");
			continue;
		}
		int len = 0, z[100];
		do {
			z[len++] = n % d;
			n /= d;
		} while (n != 0);
		for (int i = 0; i < len; i++) {
			n = n * d + z[i];
		}
		if (isPrime(n) == true) printf ("Yes\n");
		else printf ("No\n");
	}
	return 0;
}
```

