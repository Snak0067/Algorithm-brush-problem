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
//vector<int>guideMissle;
//int main() {
//	int num;
//	while (cin >> num) {
//		guideMissle.push_back(num);
//	}
//	vector<int>system;
//	for (int i = 0; i < guideMissle.size(); i++)
//	{
//		bool match = false;
//		for (int j = 0; j < system.size(); j++)
//		{
//			if (system[j] >= guideMissle[i]) {
//				system[j] = guideMissle[i];
//				match = true;
//				break;
//			}
//		}
//		if (!match) {
//			system.push_back(guideMissle[i]);
//		}
//	}
//	vector<int>dp(1);
//	dp[0] = guideMissle[0];
//	for (int i = 1; i < guideMissle.size(); i++)
//	{
//		if (guideMissle[i] <= dp.back()) {
//			dp.push_back(guideMissle[i]);
//		}
//		else {
//			int l = 0, r = dp.size() - 1;
//			while (l < r) {
//				int mid = (l + r) >> 1;
//				if (dp[mid] < guideMissle[i]) {
//					r = mid;
//				}
//				else {
//					l = mid + 1;
//				}
//			}
//			dp[l] = guideMissle[i];
//		}
//	}
//	printf("%d\n%d", dp.size(), system.size());
//	return 0;
//}