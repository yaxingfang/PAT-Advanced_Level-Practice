#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main () {
	int a, b, sum;
	string s;
	scanf ("%d %d", &a, &b);
	sum = a + b;
	s = to_string (sum);
	for (int i = 0; i < s.length(); i++) { 
		cout << s[i];
		if (s[i] == '-') continue;
		if ((i + 1) % 3 == s.length() % 3 && i != s.length() - 1) cout << ","; 
		/*ֻҪ��ǰλ���±�i����(i + 1) % 3 == len % 3����i�������һλ��
		���ڸ�λ�����ĺ������һ������*/
	}
	return 0;
}
