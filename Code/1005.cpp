#include <iostream>
#include <string>
using namespace std;
int main () {
	string a[] = {"zero", "one", "two", "three", 
	"four", "five", "six", "seven", "eight", "nine"};
	string s, ans;				//s存储原始数字，ans存储相加得到的数字 
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';		//注意加的是数字，而s[i]中是字符 
	}
	ans = to_string(sum);
	cout << a[ans[0] - '0'];	//下标也是数字，要将字符转为数字 
	for (int i = 1; i < ans.length(); i++) {
		cout << " " << a[ans[i] - '0'];
	}
	return 0;
}
