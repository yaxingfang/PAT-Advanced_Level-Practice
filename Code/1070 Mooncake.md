## 1070 Mooncake （25 分)

Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers *N* (≤1000), the number of different kinds of mooncakes, and *D*(≤500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of *N* kinds of mooncakes. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

### Sample Input:

```in
3 200
180 150 100
7.5 7.2 4.5
```

### Sample Output:

```out
9.45
```

### Code

```c++
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	double total, price;	//此处total不设置成浮点型会有一个case答案错误 
};
bool cmp (node a, node b) {
	return a.price / a.total > b.price / b.total; 
}
int main () {
	int n;
	double demand, profit = 0;
	scanf ("%d%lf", &n, &demand);
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		scanf ("%lf", &v[i].total);
	}
	for (int i = 0; i < n; i++) {
		scanf ("%lf", &v[i].price);
	}
	sort (v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (demand >= v[i].total) {
			profit += v[i].price;
			demand -= v[i].total;
		} else {
			profit += v[i].price / v[i].total * demand;
			break; 
		}
	}
	printf ("%.2f", profit);
	return 0;
}
```
