## 1046 Shortest Distance （20 分）

The task is really simple: given *N* exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

### Input Specification:

Each input file contains one test case. For each case, the first line contains an integer *N* (in [3,105]), followed by *N* integer distances *D*1 *D*2 ⋯ *D**N*, where *D**i* is the distance between the *i*-th and the (*i*+1)-st exits, and *D**N* is between the *N*-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer *M* (≤104), with *M* lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to *N*. It is guaranteed that the total round trip distance is no more than 107.

### Output Specification:

For each test case, print your results in *M* lines, each contains the shortest distance between the corresponding given pair of exits.

### Sample Input:

```in
5 1 2 4 14 9
3
1 3
2 5
4 1
```

### Sample Output:

```out
3
10
7
```

### Code

```c++
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main () {
	int n, A[maxn], dist[maxn], total = 0, m, a, b;	
	//A存储相邻两个结点之间的距离，dist存储从第一个结点到结点i下一位i+1的距离，total存储从小到大下标总距离 
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &A[i]);
		total += A[i];
		dist[i] = total;
		//此处若不使用dist存储距离，后面再进行一次遍历，会引起一个case超时	
	}
	scanf ("%d", &m);
	while (m--) {
		scanf ("%d %d", &a, &b);
		if (a > b) swap (a, b);
		int temp = dist[b - 1] - dist[a - 1];
		printf ("%d\n", min(temp, total - temp));
	}
	return 0;
} 
```

