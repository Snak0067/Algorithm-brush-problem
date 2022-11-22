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
//int mint = INT_MAX;
//int maxd = INT_MIN;
//int mg, s, ti;
//void dfs(int m, int dis, int t) {
//	maxd = max(maxd, dis);
//	if (maxd > s) {
//		mint = min(mint, ti - t);
//		return;
//	}
//	if (t == 0) {
//		return;
//	}
//	if (m >= 10) {
//		dfs(m - 10, dis + 60, t - 1);
//	}
//	if (m < 10)dfs(m + 4, dis, t - 1);
//	if (t <= 4 || (s - dis) < 100) {
//		dfs(m, dis + 17, t - 1);
//	}
//
//}
//int main() {
//	cin >> mg >> s >> ti;
//	//dfs(initialMagicValue, 0, ti);
//	//if (mint == INT_MAX) {
//	//	printf("No\n%d", maxd);
//	//}
//	//else {
//	//	printf("Yes\n%d", mint);
//	//}
//	int s1 = 0, s2 = 0;
//	for (int i = 1; i <= ti; i++)
//	{
//		s1 += 17;
//		if (mg >= 10) {
//			mg -= 10;
//			s2 += 60;
//		}
//		else {
//			mg += 4;
//		}
//		if (s2 > s1)s1 = s2;
//		if (s1 > s) {
//			cout << "Yes" << endl << i << endl;
//			return 0;
//		}
//	}
//	cout << "No" << endl << max(s1, s2) << endl;
//	return 0;
//}