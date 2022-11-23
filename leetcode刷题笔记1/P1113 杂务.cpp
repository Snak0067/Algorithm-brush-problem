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
//vector<int>v[10005];
//vector<int>mint;
//vector<int>vis;
//int dfs(int x) {
//	vis[x] = 1;
//	int maxn = 0;
//	int ans = v[x][1];
//	for (int i = 2; v[x][i] != 0; i++)
//	{
//		if (mint[v[x][i]]) {
//			maxn = max(mint[v[x][i]], maxn);
//		}
//		else {
//			maxn = max(dfs(v[x][i]), maxn);
//		}
//	}
//	mint[x] = maxn + ans;
//	return maxn + ans;
//}
//int main() {
//	int n;
//	cin >> n;
//	mint.resize(n + 1);
//	vis.assign(n + 1, -1);
//	for (int i = 1; i <= n; i++)
//	{
//		int pre, idx = 2;
//		v[i].resize(100);
//		cin >> v[i][0] >> v[i][1] >> pre;
//		while (pre != 0) {
//			v[i][idx++] = pre;
//			cin >> pre;
//		}
//	}
//	int res = 0;
//	for (int i = n; i >= 1; i--)
//	{
//		if (vis[i] == -1) {
//			res = max(res, dfs(i));
//		}
//	}
//	cout << res << endl;
//	return 0;
//}