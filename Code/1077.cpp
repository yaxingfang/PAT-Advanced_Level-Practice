#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	int n;
	scanf ("%d\n", &n);
	string s, ans;
	for (int i = 0; i < n; i++) {
		getline (cin ,s);
		reverse (s.begin(), s.end());
		if (i == 0) {
			ans = s;
			continue;
		} else {
			int minlen = min (s.length(), ans.length());
			for (int j = 0; j < minlen; j++) {
				if (s[j] != ans[j]) {
					ans = ans.substr(0, j);
					break;
				}
			}
		}
	}
	reverse (ans.begin(), ans.end());
	ans.length() == 0 ? cout << "nai" : cout << ans;
	return 0;
}
