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
//vector<int>powerOfTwo;
//string power(int restOfN, int exponential) {
//	vector<int>ans;
//	for (int i = exponential; i >= 0 && restOfN != 0; i--) {
//		if (restOfN >= powerOfTwo[i]) {
//			ans.push_back(i);
//			restOfN -= powerOfTwo[i];
//		}
//	}
//	string re;
//	for (int i = 0; i < ans.size(); i++) {
//		if (i != 0) {
//			re += "+";
//		}
//		if (ans[i] == 2) {
//			re += "2(2)";
//		}
//		else if (ans[i] == 1) {
//			re += "2";
//		}
//		else if (ans[i] == 0) {
//			re += "2(0)";
//		}
//		else {
//			int num = 1;
//			while (pow(2, num) < ans[i]) {
//				num++;
//			}
//			string temp = "2(" + power(ans[i], num) + ")";
//			re += temp;
//		}
//	}
//	return re;
//}
//int main() {
//	int i = 1, n;
//	cin >> n;
//	while (i <= n) {
//		powerOfTwo.push_back(i);
//		i = i << 1;
//	}
//	string ans = power(n, powerOfTwo.size() - 1);
//	cout << ans << endl;
//
//	return 0;
//}