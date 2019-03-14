## 1063 Set Similarity （25 分)

Given two sets of integers, the similarity of the sets is defined to be *N**c*/*N**t*×100%, where *N**c* is the number of distinct common numbers shared by the two sets, and *N**t* is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

### Input Specification:

Each input file contains one test case. Each case first gives a positive integer *N* (≤50) which is the total number of sets. Then *N* lines follow, each gives a set with a positive *M* (≤104) and followed by *M* integers in the range [0,109]. After the input of sets, a positive integer *K* (≤2000) is given, followed by *K*lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to *N*). All the numbers in a line are separated by a space.

### Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

### Sample Input:

```in
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
```

### Sample Output:

```out
50.0%
33.3%
```

### Code

```c++
#include <set>
#include <vector> 
#include <cstdio>
using namespace std;
int main () {
	int n, m, temp, num;
	scanf ("%d", &n);
	set<int> st[n + 1];
	for (int i = 1; i <= n; i++) {	//由于后面查询的下标表示从1开始 
		scanf("%d", &temp);
		for (int j = 0; j < temp; j++) {
			scanf ("%d", &num);
			st[i].insert(num);
		}
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b; 
		scanf ("%d %d", &a, &b);
		int Nc = 0, Nt = st[b].size();	//分别是重复的，不重复的 
		for (set<int>::iterator it = st[a].begin(); it != st[a].end(); it++) {
			if (st[b].find(*it) != st[b].end()) {	//对于每个a中的元素，在b中能找着 
				Nc++;				//重复元素加1 
			} else {				//找不着 
				Nt++;				//不重复元素加1 
			}
		}
		double ans = (double)Nc / Nt * 100;
		printf ("%.1f%%\n", ans);
	}
	return 0;
}
```

