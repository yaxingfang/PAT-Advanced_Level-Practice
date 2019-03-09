## 1036 Boys vs Girls （25 分）

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

### Input Specification:

Each input file contains one test case. Each case contains a positive integer *N*, followed by *N* lines of student information. Each line contains a student's `name`, `gender`, `ID` and `grade`, separated by a space, where `name` and `ID` are strings of no more than 10 characters with no space, `gender` is either `F` (female) or `M`(male), and `grade` is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

### Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference *g**r**a**d**e**F*−*g**r**a**d**e**M*. If one such kind of student is missing, output `Absent` in the corresponding line, and output `NA` in the third line instead.

### Sample Input 1:

```in
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
```

### Sample Output 1:

```out
Mary EE990830
Joe Math990112
6
```

### Sample Input 2:

```in
1
Jean M AA980920 60
```

### Sample Output 2:

```out
Absent
Jean AA980920
NA
```

### Code

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string name, gender, id;
	int grade;	
}; 
bool cmp (node a, node b) {
	return a.grade > b.grade;
}
int main () {
	vector<node> fem;
	vector<node> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node a;
		cin >> a.name >> a.gender >> a.id >> a.grade;
		if (a.gender == "F") {
			fem.push_back(a);
		} else {
			m.push_back(a);
		}
	}
	sort (fem.begin(), fem.end(), cmp);
	sort (m.begin(), m.end(), cmp);
	if (fem.size() == 0) {
		cout << "Absent" << endl;
	} else {
		cout << fem[0].name << " " << fem[0].id << endl;
	}
	if (m.size() == 0) {
		cout << "Absent" << endl;
	} else {
		cout << m[m.size() - 1].name << " " << m[m.size() - 1].id  << endl;
	}
	if (fem.size() == 0 || m.size() == 0) {
		cout << "NA" << endl;
	} else {
		cout << fem[0].grade - m[m.size() - 1].grade << endl;
	}
	return 0;
}
```

