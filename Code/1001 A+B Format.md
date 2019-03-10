## 1001 A+B Format （20 分）

Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:

Each input file contains one test case. Each case contains a pair of integers *a* and *b* where −106≤*a*,*b*≤106. The numbers are separated by a space.

### Output Specification:

For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.

### Sample Input:

```in
-1000000 9
```

### Sample Output:

```out
-999,991
```

### Code

```c++
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main () {
	int a, b, sum;
	string s;
	scanf ("%d %d", &a, &b);
	sum = a + b;
	s = to_string (sum);
	for (int i = 0; i < s.length(); i++) { 
		cout << s[i];
		if (s[i] == '-') continue;
		if ((i + 1) % 3 == s.length() % 3 && i != s.length() - 1) cout << ","; 
		/*只要当前位的下标i满足(i + 1) % 3 == len % 3并且i不是最后一位，
		就在该位输出后的后面加上一个逗号*/
	}
	return 0;
}
```

