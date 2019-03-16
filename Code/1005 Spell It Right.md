## 1005 Spell It Right （20 分）

Given a non-negative integer *N*, your task is to compute the sum of all the digits of *N*, and output every digit of the sum in English.

### Input Specification:

Each input file contains one test case. Each case occupies one line which contains an *N* (≤10100).

### Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

### Sample Input:

```in
12345
```

### Sample Output:

```out
one five
```

### Code

```c++
#include <iostream>
#include <string>
using namespace std;
int main () {
	string a[] = {"zero", "one", "two", "three", 
	"four", "five", "six", "seven", "eight", "nine"};
	string s, ans;			//s存储原始数字，ans存储相加得到的数字 
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';	//注意加的是数字，而s[i]中是字符 
	}
	ans = to_string(sum);
	cout << a[ans[0] - '0'];	//下标也是数字，要将字符转为数字 
	for (int i = 1; i < ans.length(); i++) {
		cout << " " << a[ans[i] - '0'];
	}
	return 0;
}
```

