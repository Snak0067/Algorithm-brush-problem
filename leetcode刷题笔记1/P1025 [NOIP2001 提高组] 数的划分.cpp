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
//void dfs(int cur, int k, int target) {
//	if (k == 1) {
//		ans++;
//		return;
//	}
//	while (true) {
//		if (cur > target - cur || cur > target / 2)return;
//		dfs(cur, k - 1, target - cur);
//		cur++;
//	}
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	dfs(1, k, n);
//	cout << ans << endl;
//	return 0;
//}