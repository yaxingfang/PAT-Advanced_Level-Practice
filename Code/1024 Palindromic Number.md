## 1024 Palindromic Number （25 分)

A number that will be the same when it is written forwards or backwards is known as a **Palindromic Number**. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer *N*, you are supposed to find its paired palindromic number and the number of steps taken to find it.

### Input Specification:

Each input file contains one test case. Each case consists of two positive numbers *N* and *K*, where *N* (≤1010) is the initial numer and *K* (≤100) is the maximum number of steps. The numbers are separated by a space.

### Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of *N*, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after *K* steps, just output the number obtained at the *K*th step and *K*instead.

### Sample Input 1:

```in
67 3
```

### Sample Output 1:

```out
484
2
```

### Sample Input 2:

```in
69 3
```

### Sample Output 2:

```out
1353
3
```

### Code

```c++
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
bool parlin (string s) {
	string ans = s;
	reverse (ans.begin(), ans.end());
	if (ans == s) {
		return true;
	} else {
		return false;
	}
}
string add (string a){
	string b = a, ans = a;
	reverse (b.begin(), b.end());
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		ans[i] = (a[i] - '0' + b[i] - '0' + carry) % 10 + '0';
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	if (carry != 0) ans = '1' + ans;
	return ans;
}
int main () {
	string s;
	int i, k;
	cin >> s >> k;
	int step = 0;
	//注意step = k - 1的时候还能进入，再次进入后step变成 k 
	while (step < k) {
		if (parlin(s) == true) {
			break;
		} else {
			s = add (s);
			step++;
		}
	}
	cout << s << endl;
	cout << step << endl;
	return 0;
} 
```

