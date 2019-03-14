## 1059 Prime Factors （25 分)

Given any positive integer *N*, you are supposed to find all of its prime factors, and write them in the format *N* = *p*1*k*1×*p*2*k*2×⋯×*p**m**k**m*.

### Input Specification:

Each input file contains one test case which gives a positive integer *N* in the range of **long int**.

### Output Specification:

Factor *N* in the format *N* `=` *p*1`^`*k*1`*`*p*2`^`*k*2`*`…`*`*p**m*`^`*k**m*, where *p**i*'s are prime factors of *N* in increasing order, and the exponent *k**i* is the number of *p**i*-- hence when there is only one *p**i*, *k**i* is 1 and must **NOT** be printed out.

### Sample Input:

```in
97532468
```

### Sample Output:

```out
97532468=2^2*11*17*101*1291
```

### Code

```c++
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int n;
map<int, int> mp; 
void getFactor(int n) {
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++) {
		while (n % i == 0) {
			n /= i;
			mp[i]++;
		}
	}
	if (n != 1) mp[n]++;
}
int main () {
	scanf  ("%d", &n);
	if (n == 1) {
		printf ("1=1");
		return 0;
	}
	getFactor(n);
	printf ("%d=", n);
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it != mp.begin()) printf ("*");
		if (it->second == 1) printf ("%d", it->first);
		else printf ("%d^%d", it->first, it->second);
	}
	return 0;
}
```

