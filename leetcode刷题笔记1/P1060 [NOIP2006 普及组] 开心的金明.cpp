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
//int dp[30005], v[30], w[30];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = n; j >= v[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - v[i]] + w[i] * v[i]);
//		}
//	}
//	cout << dp[n] << endl;
//	return 0;
//}