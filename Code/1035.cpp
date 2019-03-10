#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
	string id, pw;
};
int main () {
	vector<node> v;
	int n, cnt = 0;
	scanf ("%d", &n);
	for (int t = 0; t < n; t++){
		bool flag = false;
		node a;
		cin >> a.id >> a.pw;
		for (int i = 0; i < a.pw.length(); i++) {
			if (a.pw[i] == '1') {
				a.pw[i] = '@';
				flag = true;
			} else if (a.pw[i] == '0') {
				a.pw[i] = '%';
				flag = true;
			} else if (a.pw[i] == 'l') {
				a.pw[i] = 'L';
				flag = true;
			} else if (a.pw[i] == 'O') {
				a.pw[i] = 'o';
				flag = true;
			} else {
				continue;
			} 
		}
		if (flag == true) {
			cnt++;
			v.push_back(a);
		}
	}
	if (cnt == 0) {
		if (n != 1) {
			printf ("There are %d accounts and no account is modified\n", n);
		} else {
			printf ("There is 1 account and no account is modified");
		}
	} else {
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			cout << v[i].id << " " << v[i].pw << endl;
		}
	}
	return 0;
} 
