## 1074 Reversing Linked List （25 分)

Given a constant *K* and a singly linked list *L*, you are supposed to reverse the links of every *K* elements on *L*. For example, given *L* being 1→2→3→4→5→6, if *K*=3, then you must output 3→2→1→6→5→4; if *K*=4, you must output 4→3→2→1→5→6.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive *N* (≤105) which is the total number of nodes, and a positive *K* (≤*N*) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then *N* lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

### Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```

### Sample Output:

```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```

### Code

```c++
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int add, data, next;		//当前结点地址，权值，下一个结点的地址 
};

int main () {
	vector<node> vin(100000);	//初始数组 
	vector<node> vsorted;		//经过链接后的数组 
	vector<node> vout;			//经过反转后的最终数组 
	node temp; 
	int first, n, k;
	scanf ("%d %d %d", &first, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf ("%d %d %d", &temp.add, &temp.data, &temp.next);
		vin[temp.add] = temp;          
	}	
	if (first == -1) { 
		printf ("-1\n");
	} else {
		int nextadd = first;
		while (nextadd != -1) {
			vsorted.push_back(vin[nextadd]);	//第一个结点 
			nextadd = vin[nextadd].next;		//第一个结点的下一个结点 
		}
		int N = vsorted.size();
		int pos = k - 1;
		while (pos < N) {
			for (int i = pos; i >= pos - k + 1; i--) {
				vout.push_back(vsorted[i]);
			} 
			pos += k;
		}
		for (int i = pos + 1 - k; i < N; i++) {
			vout.push_back(vsorted[i]);
		}
		for (int i = 0; i < N-1; i++) {
			vout[i].next = vout[i + 1].add;
			printf ("%05d %d %05d\n", vout[i].add, vout[i].data, vout[i].next);
		}
		printf ("%05d %d %d\n", vout[N - 1].add, vout[N - 1].data, -1); 
	}
	return 0;
} 
```

