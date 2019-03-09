## 1061 Dating （20 分）

Sherlock Holmes received a note with some strange strings: `Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`. It took him only a minute to figure out that those strange strings are actually referring to the coded time `Thursday 14:04` -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter `D`, representing the 4th day in a week; the second common character is the 5th capital letter `E`, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from `A` to `N`, respectively); and the English letter shared by the last two strings is `s` at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

### Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

### Output Specification:

For each test case, print the decoded time in one line, in the format `DAY HH:MM`, where `DAY` is a 3-character abbreviation for the days in a week -- that is, `MON` for Monday, `TUE` for Tuesday, `WED` for Wednesday, `THU` for Thursday, `FRI` for Friday, `SAT` for Saturday, and `SUN` for Sunday. It is guaranteed that the result is unique for each case.

### Sample Input:

```in
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
```

### Sample Output:

```out
THU 14:04
```

### Code

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
int main () {
	char day[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"} ; //二维数组存储字符串数组 
	char a[60], b[60], c[60], d[60] ;
	scanf ("%s", a) ;
	scanf ("%s", b) ;
	scanf ("%s", c) ;
	scanf ("%s", d) ;
	int i ;
	//ABCD对应 "MON" "TUE" "WED""THU" 
	for (i=0; i<min(strlen(a), strlen(b)); i++) {
		if (a[i] == b[i] && a[i] >='A'&&a[i]<='G') {
			printf("%s ", day[a[i]-'A']) ;
			break ;				 
		}
	}
	//0 1 2...9 10 11 ... 23 对应 
	//0 1 2...9 A B C ... N 
	for (i=i+1; i<min(strlen(a), strlen(b)); i++) { //找第二个相同 i从上一个i+1开始 
		if (a[i] == b[i]) {
			if (a[i]>='0'&&a[i]<='9') {
				printf ("%02d", a[i]-'0') ;
				break ;
			} else if (a[i]>='A'&&a[i]<='N') {
				printf ("%02d", a[i]-'A'+10 ) ; 
				break ;
			}
		}
	}
	//数组下标就是分钟 
	for (i=0; i<min(strlen(c), strlen(d)); i++) {
		if (c[i] == d[i]) {
			if ((c[i]>='A'&&c[i]<='Z')  || (c[i]>='a'&&c[i]<='z')) {
				printf (":%02d", i) ;
				break ;
			}
		}
	}
	return 0 ;
} 
//注意点：每次寻找到合理的解一定要记得break 若不break则会再次进入循环导致错误 
```

