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
//#include<cstring>
//#include<limits.h>
//using namespace std;
//int dp[2005][2005];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	memset(dp, 0, sizeof(dp));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> dp[i][j];
//		}
//	}
//	for (int j = 1; j < n; j++)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			if (i == 0) {
//				dp[i][j] = min(dp[i][j - 1], dp[m - 1][j - 1]) + dp[i][j];
//			}
//			else {
//				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1]) + dp[i][j];
//			}
//		}
//	}
//	int minn = INT_MAX;
//	for (int i = 0; i < m; i++)
//	{
//		minn = min(minn, dp[i][n - 1]);
//	}
//	cout << minn << endl;
//	return 0;
//}