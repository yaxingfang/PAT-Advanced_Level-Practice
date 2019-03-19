## 1003 Emergency （25 分)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: *N* (≤500) - the number of cities (and the cities are numbered from 0 to *N*−1), *M* - the number of roads, *C*1 and *C*2 - the cities that you are currently in and that you must save, respectively. The next line contains *N* integers, where the *i*-th integer is the number of rescue teams in the *i*-th city. Then *M* lines follow, each describes a road with three integers *c*1, *c*2 and *L*, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from *C*1 to *C*2.

### Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between *C*1 and *C*2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

### Sample Input:

```in
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```

### Sample Output:

```out
2 4
```

### Code

```c++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];	//顶点数，边数，起点，终点，邻接矩阵，点权 
int d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = {false};

void Dijkstra (int s) {
	fill (d, d + MAXV, INF);
	fill (w, w + MAXV, 0);
	fill (num, num + MAXV, 0);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				} else if (d[u] + G[u][v] == d[v]) {
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}

int main () {
	cin >> n >> m >> st >> ed;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	Dijkstra (st);
	cout << num[ed] << " " << w[ed];
	return 0;
}
```

