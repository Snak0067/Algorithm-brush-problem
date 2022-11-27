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
//int v[105];
//int sum[105];
//int temp;
//int n, m, ans = 0;
///*搜索方法，只能过一些样例简单的测试点*/
//void dfs(int i) {
//	int lastSum = temp + sum[n] - sum[i - 1];
//	if (temp > m || i > n + 1 || lastSum < m) {
//		return;
//	}
//	if (temp == m) {
//		ans++;
//		return;
//	}
//	temp += v[i];
//	dfs(i + 1);
//	temp -= v[i];
//	dfs(i + 1);
//}
//void searchTest() {
//	dfs(1);
//	cout << ans << endl;
//}
///*dp动态规划解法*/
////前i道菜花了j元的办法的总数
//int dp[105][10005] = { 0 };
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v[i];
//		sum[i] = sum[i - 1] + v[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			if (j == v[i]) {
//				dp[i][j] = dp[i - 1][j] + 1;
//			}
//			if (j > v[j]) {
//				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i]];
//			}
//			if (j < v[i]) {
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//
//	}
//	cout << dp[n][m] << endl;
//	return 0;
//}