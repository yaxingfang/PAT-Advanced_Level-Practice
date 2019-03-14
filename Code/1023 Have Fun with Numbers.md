## 1023 Have Fun with Numbers （20 分)

Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with *k* digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

### Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

### Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

### Sample Input:

```in
1234567899
```

### Sample Output:

```out
Yes
2469135798
```

### Code

```c++
#include <cstdio> 
#include <string>
#include <iostream>
using namespace std;
int main () {
	bool flag = true;
	string s;
	cin >> s;
	string ans = s;
	int carry = 0, count [10] = {0};	//count记录每个数字的个数 
	for (int i = s.length() - 1; i >= 0; i--) {
		count[s[i] - '0']++;			 
		ans[i] = ((s[i] - '0') * 2 + carry) % 10 + '0';
		//千万注意这儿是ans[i]不能直接ans += 字符，这而是按位操作一位位的走 
		count[ans[i] - '0']--;
		carry = ((s[i] - '0') * 2 + carry) / 10;
	}
	if (carry != 0) {
		ans = '1' + ans;
		count[1]--;
	}
	for (int i = 0; i < 10; i++) {
		if (count [i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag == true) printf ("Yes\n");
	else printf ("No\n");
	cout << ans << endl;
	return 0;
}
```

