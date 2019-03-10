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
		/*只要当前位的下标i满足(i + 1) % 3 == len % 3并且i不是最后一位，
		就在该位输出后的后面加上一个逗号*/
	}
	return 0;
}
