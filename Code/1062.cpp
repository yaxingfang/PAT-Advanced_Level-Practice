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
		}
	}
	return 0;
}
