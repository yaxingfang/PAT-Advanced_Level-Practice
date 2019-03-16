## 1100 Mars Numbers （20 分)

People on Mars count their numbers with base 13:

- Zero on Earth is called "tret" on Mars.
- The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
- For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.

For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer *N* (<100). Then *N* lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

### Output Specification:

For each number, print in a line the corresponding number in the other language.

### Sample Input:

```in
4
29
5
elo nov
tam
```

### Sample Output:

```out
hel mar
may
115
13
```

### Code

```c++
#include <iostream>
#include <string>
using namespace std;

string a1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
//低位：对应 x % 13 下标 
string a2[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
//高位：对应 x / 13 - 1 下标 

int main () {
	int n;			//n行 
	string temp;		//temp表示当前字符串
	cin>>n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, temp);	
		int len = temp.length();			//当前字符串长度 
		int a = 0;									
		if (temp[0] >= '0' && temp[0] <= '9') {		//这是数字 
			for (int j = 0; j < len; j++) {
				a = a * 10 + temp[j] - '0';	//将字符串转成整型a，再到相应数组里面找对应的火星文string 
			}
			if (a < 13) {				//比13小，只输出低位 
				cout<<a1[a]<<endl;
			} else if (a % 13 == 0) {		//整数倍只输出高位 
				cout<<a2[a / 13 - 1]<<endl;
			} else {				//输出 高位 低位 
				cout<<a2[a /13 - 1]<<" "<<a1[a % 13]<<endl;
			}
		}
		else {						//这是火星文字符串 
			int num = 0;				//num存储最终输出的整型数字 
			for (int i = 0; i < len; i += 4) {	//处理前半段012位和后半段456位 
				string ans = ""; 		//ans存储处理后的字符串 
				ans = ans + temp[i] + temp[i + 1] + temp[i + 2];
				for (int j = 0; j < 13; j++) {
					if (ans == a1[j]) {				
						num += j;
						break;
					}
					if (ans == a2[j]) {
						num += (j + 1) * 13;
						break;
					}
				}
			}
			cout<<num<<endl;
		}
		
	}
	return 0;
}
```

