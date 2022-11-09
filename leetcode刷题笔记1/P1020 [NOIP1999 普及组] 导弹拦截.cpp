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
//vector<int>missle;
//int main() {
//	int cnt = 1;
//	string heights;
//	getline(cin, heights);
//	int num = 0;
//	for (int i = 0; i < heights.length(); i++) {
//		if (heights[i] == ' ') {
//			missle.push_back(num);
//			num = 0;
//		}
//		else {
//			num = num * 10 + heights[i] - '0';
//		}
//	}
//	missle.push_back(num);
//	//计算需要多少系统:每个系统最低的位置
//	vector<int>system;
//	for (int i = 0; i < missle.size(); i++) {
//		//判断二分左右两边的情况
//		if (system.size() > 0) {
//			if (missle[i] < system[0]) {
//				system[0] = missle[i];
//				continue;
//			}
//			else if (missle[i] > system.back()) {
//				system.push_back(missle[i]);
//				continue;
//			}
//		}
//		else {
//			system.push_back(missle[i]);
//			continue;
//		}
//		//判断中间的情况
//		int l = 0, r = system.size() - 1;
//		while (l < r) {
//			int mid = (l + r) >> 1;
//			if (system[mid] < missle[i]) {
//				l = mid + 1;
//			}
//			else if (system[mid] > missle[i]) {
//				r = mid;
//			}
//			else {
//				l = mid + 1;
//				break;
//			}
//		}
//		system[l] = missle[i];
//	}
//	vector<int>dp(missle.size());
//	dp[0] = 1;
//	for (int i = 1; i < missle.size(); i++) {
//		for (int j = 0; j < i; j++)
//		{
//			if (missle[i] < missle[j]) {
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//			else {
//				dp[i] = max(1, dp[i]);
//			}
//		}
//	}
//	int maxl = INT_MIN;
//	for (int i = 0; i < dp.size(); i++)
//	{
//		maxl = max(maxl, dp[i]);
//	}
//	cout << maxl << endl;
//	cout << system.size() << endl;
//
//	return 0;
//}