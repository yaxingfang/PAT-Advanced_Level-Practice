## 1078 Hashing （25 分)

The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be *H*(*k**e**y*)=*k**e**y*%*T**S**i**z**e* where *T**S**i**z**e* is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

### Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: *M**S**i**z**e* (≤104) and *N* (≤*M**S**i**z**e*) which are the user-defined table size and the number of input numbers, respectively. Then *N* distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

### Sample Input:

```in
4 4
10 6 4 15
```

### Sample Output:

```out
0 1 4 -
```

### Code

```c++
//二次探测：使用 (key + step * step) % size 
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 10010;
int n, k, hashTable[maxn];
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

void output (int x) {
    for(int i = 0; i < n; i++) {
        int index = (x + i * i) % n;
        if(hashTable[index] == 0) {
            hashTable[index] = 1;
            cout << index % n;
            return ;
        }
    }
    cout << '-';
}
int main () {
	int x;
	scanf ("%d%d", &n, &k);
	while (!isPrime (n)) {
		n++;
	} 
	for (int i = 0; i < k; i++) {
		scanf ("%d", &x);
		if (i != 0) printf (" ");
		output (x);
	} 
	return 0;
}
```

