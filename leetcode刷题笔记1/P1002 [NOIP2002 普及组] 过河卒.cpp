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
//using namespace std;
//int b1, b2, horse1, horse2;
//int horsePoints[40][40];
//vector<vector<int>>v = { {-2,-1},{-2,1},{2,1},{2,-1}, {1,2},{1,-2},{-1,2},{-1,-2} };
//vector<vector<long long>>dp;
//
//int main() {
//	cin >> b1 >> b2 >> horse1 >> horse2;
//	dp.assign(b1 + 1, vector<long long>(b2 + 1, 0));
//	horsePoints[horse1][horse2] = 1;
//	for (vector<int>vec : v) {
//		int x = vec[0] + horse1;
//		int y = vec[1] + horse2;
//		if (x >= 0 && x <= b1 && y >= 0 && y <= b2)horsePoints[x][y] = 1;
//	}
//	dp[0][0] = 1;
//	for (int i = 0; i <= b1; i++) {
//		for (int j = 0; j <= b2; j++) {
//			if (i == 0 && j == 0)continue;
//			if (horsePoints[i][j] == 1)continue;
//			else if (i == 0)dp[i][j] = dp[i][j - 1];
//			else if (j == 0)dp[i][j] = dp[i-1][j];
//			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	printf("%lld", dp[b1][b2]);
//	return 0;
//}