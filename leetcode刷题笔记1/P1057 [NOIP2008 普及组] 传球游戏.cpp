#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;
//int ans = 0;
//int n, m;//n个同学，m次传球
//void dfs(int holder, int time) {
//	if (time == 0) {
//		if (holder == 0) {
//			ans++;
//		}
//		return;
//	}
//	int left = (holder - 1 == -1 ? n - 1 : holder - 1);
//	int right = (holder + 1 == n ? 0 : holder + 1);
//	dfs(left, time - 1);
//	dfs(right, time - 1);
//
//}
//int main() {
//	cin >> n >> m;
//	dfs(0, m);
//	cout << ans << endl;
//	return 0;
//}