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
//	int n, num;
//	cin >> n;
//	string ans;
//	for (int i = 0; i <= n; i++)
//	{
//		cin >> num;
//		if (num == 0)continue;
//		int power = n - i;
//		if (num > 0) {
//			ans += "+";
//		}
//		string strnum = to_string(num);
//		if (fabs(num) == 1 && i != n) {
//			strnum.pop_back();
//		}
//		if (i == n) {
//			ans += strnum;
//		}
//		else if (i == n - 1) {
//			ans += strnum + "x";
//		}
//		else {
//			ans += strnum + "x^" + to_string(n - i);
//		}
//	}
//	if (ans[0] == '+')ans = ans.substr(1);
//	cout << ans << endl;
//	return 0;
//}