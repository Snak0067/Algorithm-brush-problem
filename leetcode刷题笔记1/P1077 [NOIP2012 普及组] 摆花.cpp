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
//int limit[105];
//int cnt[105];
//int dp[105][105];
//int n, m;
//int dfs(int idx, int x) {
//	int ans = 0;
//	if (x > cnt[idx] || x < n - idx) {
//		dp[idx][x] = -1;
//		return 0;
//	}
//	if (idx == n - 1) {
//		if (x <= limit[idx]) {
//			dp[idx][x] = 1;
//			return 1;
//		}
//		dp[idx][x] = -1;
//		return 0;
//	}
//	for (int i = 1; i <= limit[idx]; i++)
//	{
//		if (dp[idx + 1][x - i] == 0) {
//			ans += dfs(idx + 1, x - i);
//		}
//		else {
//			if (dp[idx + 1][x - i] > 0) {
//				ans += dp[idx + 1][x - i];
//			}
//		}
//	}
//	dp[idx][x] = ans;
//	return ans;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> limit[i];
//	}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		if (i != n - 1) {
//			cnt[i] = cnt[i + 1] + limit[i];
//		}
//		else {
//			cnt[i] = limit[i];
//		}
//	}
//	fill(dp[0], dp[0] + 105 * 105, 0);
//	dfs(0, m);
//	cout << dp[0][m] << endl;
//	return 0;
//}