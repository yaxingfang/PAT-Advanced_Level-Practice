#include <iostream>
#include <string>
using namespace std;
int main () {
	string a[] = {"zero", "one", "two", "three", 
	"four", "five", "six", "seven", "eight", "nine"};
	string s, ans;				//s�洢ԭʼ���֣�ans�洢��ӵõ������� 
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';		//ע��ӵ������֣���s[i]�����ַ� 
	}
	ans = to_string(sum);
	cout << a[ans[0] - '0'];	//�±�Ҳ�����֣�Ҫ���ַ�תΪ���� 
	for (int i = 1; i < ans.length(); i++) {
		cout << " " << a[ans[i] - '0'];
	}
	return 0;
}
