//#include<iostream>
//#include<unordered_map>
//#include<set>
//#include<vector>
//#include<string>
//#include<cmath>
//#include<algorithm>
//#include<map>
//#include<stack>
//#include<unordered_set>
//#include<queue>
//#include<limits.h>
//using namespace std;
//string sumOfTwoBigNum(string a, string b) {
//	if (a == "" || b == "") {
//		return a == "" ? b : a;
//	}
//	string ans;
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//	int flag = 0, idxa = 0, idxb = 0;
//	while (idxa < a.length() || idxb < b.length()) {
//		char ca = '0', cb = '0';
//		if (idxa < a.length()) {
//			ca = a[idxa];
//			idxa++;
//		}
//		if (idxb < b.length()) {
//			cb = b[idxb];
//			idxb++;
//		}
//		char temp = ca + cb - '0' + flag;
//		if (temp > '9') {
//			temp -= 10;
//			flag = 1;
//		}
//		else {
//			flag = 0;
//		}
//		ans.push_back(temp);
//	}
//	if (flag == 1)ans.push_back('1');
//	reverse(ans.begin(), ans.end());
//	return ans;
//}
//string mulOfTwoBigNum(string a, string b) {
//	string ans;
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//	for (int i = 0; i < a.length(); i++) {
//		int flag = 0;
//		string add = "";
//		for (int j = 0; j < b.length(); j++)
//		{
//			char ca = a[i];
//			char cb = b[j];
//			int temp = (ca - '0') * (cb - '0') + flag;
//			int single = temp % 10;
//			flag = temp / 10;
//			add.push_back(single + '0');
//		}
//		if (flag != 0) {
//			add.push_back('0' + flag);
//		}
//		reverse(add.begin(), add.end());
//		for (int u = 0; u < i; u++) {
//			add.push_back('0');
//		}
//		ans = sumOfTwoBigNum(ans, add);
//	}
//	return ans;
//}
//int main() {
//	int n;
//	cin >> n;//411
//	long long factorial = 1;
//	long long sumOfFactorial = 0;
//	for (int i = 1; i <= min(20, n); i++) {
//		factorial *= i;
//		sumOfFactorial += factorial;
//	}
//	string begin20 = to_string(factorial);
//	string sumFrom20 = to_string(sumOfFactorial);
//	for (int i = 21; i <= n; i++)
//	{
//		string multiplier = to_string(i);
//		begin20 = mulOfTwoBigNum(multiplier, begin20);
//		sumFrom20 = sumOfTwoBigNum(sumFrom20, begin20);
//	}
//	cout << sumFrom20 << endl;
//	return 0;
//}
//
