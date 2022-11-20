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
//int ans = 0;
//int dp[31][31];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	dp[0][1] = 1;
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (j == 1) {
//				dp[i][j] = dp[i - 1][n] + dp[i - 1][2];
//			}
//			else if (j == n) {
//				dp[i][j] = dp[i - 1][1] + dp[i - 1][n - 1];
//			}
//			else {
//				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
//			}
//		}
//	}
//	cout << dp[m][1] << endl;
//	return 0;
//}
