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
//
//int main() {
//	string s;
//	cin >> s;
//	int mul = 1, sum = 0;
//	for (int i = 0; i < s.length() - 1; i++)
//	{
//		if (i == 1 || i == 5 || i == 11)continue;
//		sum += (s[i] - '0') * mul;
//		mul++;
//	}
//	sum %= 11;
//	if (sum == 10 && s.back() == 'X' || sum + '0' == s.back()) {
//		cout << "Right" << endl;
//	}
//	else {
//		s.pop_back();
//		if (sum == 10) {
//			cout << s << "X" << endl;
//		}
//		else {
//			char c = sum + '0';
//			cout << s << c << endl;
//		}
//	}
//	return 0;
//}