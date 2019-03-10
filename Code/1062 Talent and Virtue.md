## 1062 Talent and Virtue （25 分）

About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

### Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: *N* (≤105), the total number of people to be ranked; *L* (≥60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and *H* (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below *H* but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below *H*, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the *L* line are ranked after the "fool men".

Then *N* lines follow, each gives the information of a person in the format:

```
ID_Number Virtue_Grade Talent_Grade
```

where `ID_Number` is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.

### Output Specification:

The first line of output must give *M* (≤*N*), the total number of people that are actually ranked. Then *M* lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

### Sample Input:

```in
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
```

### Sample Output:

```out
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
```

### Code

```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct node {
	string id;
	int vg, tg;
}; 
bool cmp (node a, node b) {
	if (a.vg + a.tg != b.vg + b.tg) {
		return a.vg + a.tg > b.vg + b.tg;
	} else if (a.vg != b.vg) {
		return a.vg > b.vg;
	} else {
		return a.id < b.id;
	}
}

int main () {
	int N, L, H;
	scanf ("%d %d %d\n", &N, &L, &H);
	int cnt = N;
	vector<vector<node> > v(4);
	for (int i = 0; i < N; i++) {
		node a;
		cin >> a.id >> a.vg >> a.tg;
		/*先除掉不合格的人然后再合格的人里面进行分类*/
		if (a.vg < L || a.tg < L) {	
			cnt--;	
			continue;					
		} else if (a.vg >= H && a.tg >= H) {
			v[0].push_back(a);
		} else if (a.vg >= H && a.tg < H) {
			v[1].push_back(a);
		} else if (a.vg < H && a.tg < H && a.vg >= a.tg) {
			v[2].push_back(a);
		} else {
			v[3].push_back(a);
		}
	}
	printf ("%d\n", cnt);
	for (int i = 0; i < 4; i++) {
		sort (v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j].id;
			printf (" %d %d\n", v[i][j].vg, v[i][j].tg);
            /*此处输出三个量的时候，如果直接使用 
            cout << v[i][j].id << " " <<  v[i][j].vg << " " << v[i][j].tg << endl; 
            测试点3、4均超时，改用printf后全部通过
            */
		}
	}
	return 0;
}
```

