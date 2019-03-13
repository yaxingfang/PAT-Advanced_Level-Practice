## 1047 Student List for Course （25 分)

Zhejiang University has 40,000 students and provides 2,500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: *N* (≤40,000), the total number of students, and *K* (≤2,500), the total number of courses. Then *N* lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number *C* (≤20) which is the number of courses that this student has registered, and then followed by *C* course numbers. For the sake of simplicity, the courses are numbered from 1 to *K*.

### Output Specification:

For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

### Sample Input:

```in
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
```

### Sample Output:

```out
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
```

### Code

*此题一开始使用两个 vector，一个  vector 存储学生信息，另一个 vector 存储每道题的信息，vector[1] ~ vector[k] 存储每道题里面的node*

**结果：内存超出**

```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct node {
	string name;
	int coursenum;
	vector<int> courseid;
};
bool cmp (node a, node b) {
	return a.name < b.name;
}
int main () {
	int n, k;
	scanf ("%d%d", &n, &k);
	vector<node> v(n);
	vector<vector<node> > ans(k + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].coursenum;
		v[i].courseid.resize(v[i].coursenum);
		for (int j = 0; j < v[i].coursenum; j++) {
			cin >> v[i].courseid[j];
			ans[v[i].courseid[j]].push_back(v[i]); 
		}
	}
	for (int i = 1; i <= k; i++) {
		sort(ans[i].begin(), ans[i].end(), cmp);
	}
	for (int i = 1; i <= k; i++) {
		printf ("%d %d\n", i, ans[i].size());
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j].name << endl;
		}
	}
	return 0;
}
```

*换用二维数组存储学生的姓名，并将姓名所对应下标压入course数组中，通过下标去查询name*

**结果：AC**

```C++
#include <cstdio>
/*将遍历的每个人的下标放进name数组，输出的时候按下标输出对应的name*/ 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char name[40010][5];		//name数组存储名字，可以根据下标找到对应的名字 
vector<int> course[2510];
/*course动态数组中存储的是选了该门课学生的name中下标 
直接course[]表明多门课程，压入的时候直接压入*/ 
bool cmp (int a, int b) {
	return strcmp (name[a], name[b]) < 0;
}
int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int cnt, courseid;	
		scanf ("%s %d", &name[i], &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf ("%d", &courseid);
			course[courseid].push_back(i);	//将该下标推进其对应的课程id中	
		}
	}
	for (int i = 1; i <= k; i++) {
		sort (course[i].begin(), course[i].end(), cmp);
		printf ("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); j++) {
			printf ("%s\n", name[course[i][j]]);	
			//course[i]表示第i门课程，course[i][j]表示第i门课下的下标为j的学生，到name数组中去查该下标对应的名字 
		}
	}
	return 0;
} 
```

