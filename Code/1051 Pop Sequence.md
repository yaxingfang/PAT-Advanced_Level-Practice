## 1051 Pop Sequence （25 分)

Given a stack which can keep *M* numbers at most. Push *N* numbers in the order of 1, 2, 3, ..., *N* and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if *M* is 5 and *N* is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): *M* (the maximum capacity of the stack), *N* (the length of push sequence), and *K* (the number of pop sequences to be checked). Then *K* lines follow, each contains a pop sequence of *N* numbers. All the numbers in a line are separated by a space.

### Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

### Sample Input:

```in
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```

### Sample Output:

```out
YES
NO
NO
YES
NO
```

### Code

```c++
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1010;
int main () {
	int m, n, k, a[maxn];
	cin >> m >> n >> k;
	stack<int> st;
	while (k--) {
		while (!st.empty()) {	//每次都要先将栈置为空 
			st.pop();
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int pos = 1;			//当前位置 
		bool flag = true;		//flag表示M满足弹出序列 
		for (int i = 1; i <= n; i++) {
			st.push(i);
			if (st.size() > m) { 
				flag = false;
				break;
			}
			while (!st.empty() && st.top() == a[pos]) {	//如果当前位置等于栈顶元素则将栈顶元素弹出并比较下一个 
				st.pop();
				pos++;
			}
		}
		if (flag == true && st.empty() == true) {	//最后如果满足序列并且栈中无元素了 
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
} 
```

