#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main () {
	int n, m, add, A[maxn], cnt = 0;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
		cnt++;
	}
	sort(A, A + cnt);
	int i = 0, j = cnt - 1;
	while (i < j) {
		if (A[i] + A[j] > m) {
				j--;
		} else if (A[i] + A[j] < m) {
			i++;
		} else {
			break;
		}	
	}
	if (i == j)  {
		printf ("No Solution");
	} else {
		printf ("%d %d", A[i], A[j]);
	}
	return 0; 
} 
