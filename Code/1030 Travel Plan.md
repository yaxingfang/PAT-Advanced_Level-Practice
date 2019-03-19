## 1030 Travel Plan （30 分)

A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

### Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers *N*, *M*, *S*, and *D*, where *N* (≤500) is the number of cities (and hence the cities are numbered from 0 to *N*−1); *M* is the number of highways; *S* and *D* are the starting and the destination cities, respectively. Then *M* lines follow, each provides the information of a highway, in the format:

```
City1 City2 Distance Cost
```

where the numbers are all integers no more than 500, and are separated by a space.

### Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

### Sample Input:

```in
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
```

### Sample Output:

```out
0 2 3 3 40
```

### Code

```c++
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 510;		//最大顶点数 
const int INF = 1000000000;	//无穷大
//顶点数，边数，起点，终点，距离，花费 
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
bool vis[MAXV] = {false};
//d[]记录最短距离，c[]记录最少花费，pre[]记录前驱 
int d[MAXV], c[MAXV], pre[MAXV];
void Dijkstra (int s) {
	//初始化
	fill (d, d + MAXV, INF);
	fill (c, c + MAXV, INF);
	for (int i = 0; i < n; i++) {
		pre[i] = i;
	} 
	d[s] = 0;
	c[s] = 0;
	//找当前最短距离 
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//找不到说明不通，找到则置为已访问 
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if (d[u] + G[u][v] == d[v]) {
					if (c[u] + cost[u][v] < c[v]) {
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
						
					}
				}
			}
		} 
	}
} 
//打印到v的最短路径 
void DFS (int v) {、
	//递归边界 
	if (v == st) {
		cout << v << " ";
		return;
	}
	//递归式 
	DFS(pre[v]);
	cout << v << " ";
}
int main () {
	cin >> n >> m >> st >> ed;
	int u, v;
	fill (G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cin >> G[u][v] >> cost[u][v];
		//无向边 
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra (st);	//以st为起点 
	DFS(ed);		//打印到ed的最短路径 
	cout << d[ed] << " " << c[ed];	//打印到ed的最短距离和最少花费 
	return 0;
}
```

