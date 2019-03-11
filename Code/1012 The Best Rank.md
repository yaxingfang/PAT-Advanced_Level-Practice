## 1012 The Best Rank （25 分）

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: `C` - C Programming Language, `M` - Mathematics (Calculus or Linear Algrbra), and `E` - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of `C`, `M`, `E` and `A` - Average of 4 students are given as the following:

```
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
```

Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers *N* and *M* (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then *N* lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of `C`, `M` and `E`. Then there are *M* lines, each containing a student ID.

### Output Specification:

For each of the *M* students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as `A` > `C` > `M` > `E`. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output `N/A`.

### Sample Input:

```in
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
```

### Sample Output:

```out
1 C
1 M
1 E
1 A
3 A
N/A
```

### Code

```c++
#include <vector>
#include <string> 
#include <algorithm>
#include <iostream>
using namespace std;
struct node {
	string id;
	int C, M , E, A;
	int C_rank, M_rank, E_rank, A_rank;
};
//四种排序方式 
bool cmpC (node a, node b) {
	return a.C > b.C;
}
bool cmpM (node a, node b) {
	return a.M > b.M;
}
bool cmpE (node a, node b) {
	return a.E > b.E;
}
bool cmpA (node a, node b) {
	return a.A > b.A;
}
int main () {
	int n, m;	//总人数和要check的人数 
	scanf ("%d %d", &n, &m);
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		node x;
		cin >> x.id;
		scanf ("%d%d%d", &x.C, &x.M, &x.E);
		//通过计算给出例子的平均数得出平均数是四舍五入后的结果 
		x.A = (int)((x.C + x.M + x.E) / 3 + 0.5);
		v.push_back(x); 
	}
	//注意排名方式：11345 
	sort (v.begin(), v.end(), cmpC);
	for (int i = 0; i < n; i++) {
		if (i == 0) v[0].C_rank = 1; 
		else if (v[i].C == v[i-1].C) v[i].C_rank = v[i-1].C_rank;
		else v[i].C_rank = i + 1;
	}		
	sort (v.begin(), v.end(), cmpM);
		for (int i = 0; i < n; i++) {
		if (i == 0) v[0].M_rank = 1; 
		else if (v[i].M == v[i-1].M) v[i].M_rank = v[i-1].M_rank;
		else v[i].M_rank = i + 1;
	}	
	sort (v.begin(), v.end(), cmpE);
		for (int i = 0; i < n; i++) {
		if (i == 0) v[0].E_rank = 1; 
		else if (v[i].E == v[i-1].E) v[i].E_rank = v[i-1].E_rank;
		else v[i].E_rank = i + 1;
	}	
	sort (v.begin(), v.end(), cmpA);
		for (int i = 0; i < n; i++) {
		if (i == 0) v[0].A_rank = 1; 
		else if (v[i].A == v[i-1].A) v[i].A_rank = v[i-1].A_rank;
		else v[i].A_rank = i + 1;
	}	
	string checkid;
	for (int i = 0; i < m; i++) {	//输出ACME的priority规则下的最高排名
		cin >> checkid;
		for (int j = 0; j < n; j++) {
			if(checkid == v[j].id) {
				int max_rank = v[j].A_rank; 
				char max_rank_kemu = 'A';
				if (v[j].C_rank < max_rank) {
					max_rank = v[j].C_rank;
					max_rank_kemu = 'C';
				}
				if (v[j].M_rank < max_rank) {
					max_rank = v[j].M_rank;
					max_rank_kemu = 'M';
				}
				if (v[j].E_rank < max_rank) {
					max_rank = v[j].E_rank;
					max_rank_kemu = 'E';
				}
				cout<< max_rank <<" "<< max_rank_kemu << endl;
				break;
			}
			if(j == n - 1) cout<<"N/A"<<endl;
		}
	}
}
```

