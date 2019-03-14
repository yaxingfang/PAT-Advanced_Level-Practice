## 1060 Are They Equal （25 分)

If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

### Input Specification:

Each input file contains one test case which gives three numbers *N*, *A* and *B*, where *N* (<100) is the number of significant digits, and *A* and *B* are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

### Output Specification:

For each test case, print in a line `YES` if the two numbers are treated equal, and then the number in the standard form `0.d[1]...d[N]*10^k` (`d[1]`>0 unless the number is 0); or `NO` if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

### Sample Input 1:

```in
3 12300 12358.9
```

### Sample Output 1:

```out
YES 0.123*10^5
```

### Sample Input 2:

```in
3 120 128
```

### Sample Output 2:

```out
NO 0.120*10^3 0.128*10^3
```

### Code

```c++
#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string s, int& e){
	int k = 0;
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());
			e--;
		}
	}
	else{
		while(k < s.length() && s[k] != '.'){
			k++;
			e++;
		}
		if(k < s.length()){
			s.erase(s.begin() + k);
		}
	}
	if(s.length() == 0){
		e = 0;
	}
	int num = 0;
	k = 0;
	string res;
	while(num < n){
		if(k < s.length()) res += s[k++];
		else res += '0';
		num++;
	}
	return res;
} 
 
int main(){
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2){
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	}
	else{
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
}
```

