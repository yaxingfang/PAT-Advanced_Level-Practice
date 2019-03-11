## 1025 PAT Ranking （25 分）

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number *N* (≤100), the number of test locations. Then *N* ranklists follow, each starts with a line containing a positive integer *K* (≤300), the number of testees, and then *K* lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

```
registration_number final_rank location_number local_rank
```

The locations are numbered from 1 to *N*. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

### Sample Input:

```in
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
```

### Sample Output:

```out
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
```

### Code

```c++
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string id;
	int score, final_rank, loc_num, loc_rank;
}; 
bool cmp (node a, node b) {
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main () {
	int n, m;
	scanf ("%d", &n);
	vector<node> ans;		//存储所有学生信息来最终排名 
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		vector<node> v(m);
		for (int j = 0; j < m; j++) {
			cin >> v[j].id >> v[j].score;
			v[j].loc_num = i;
		}
		sort (v.begin(), v.end(), cmp);
		v[0].loc_rank = 1;	
		ans.push_back(v[0]);	//设置为第一名记得要将其加入数组 
		for (int k = 1; k < v.size(); k++) {
			v[k].loc_rank = (v[k].score == v[k - 1].score) ? (v[k - 1].loc_rank) : (k + 1);
			ans.push_back(v[k]);
		}
	}
	sort (ans.begin(), ans.end(), cmp);
	ans[0].final_rank = 1;
	for (int i = 1; i < ans.size(); i++) {
		ans[i].final_rank = (ans[i].score == ans[i - 1].score) ? (ans[i - 1].final_rank) : (i + 1);
	}
	printf ("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].id;
		printf (" %d %d %d\n", ans[i].final_rank, ans[i].loc_num, ans[i].loc_rank);
	}
	return 0;
}
```

