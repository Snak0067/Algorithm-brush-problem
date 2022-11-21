//#include<iostream>
//#include<unordered_map>
//#include<set>
//#include<vector>
//#include<string>
//#include<cmath>
//#include<algorithm>
//#include<map>
//#include<stack>
//#include<queue>
//#include<cstring>
//#include<limits.h>
//using namespace std;
//int dp[1005][1005];
//int vis[1005][1005];
//vector<string>v;
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//vector<pair<int, int>>record;
//int main() {
//	fill(dp[0], dp[0] + 1005 * 1005, 1);
//	fill(vis[0], vis[0] + 1005 * 1005, -1);
//	int n, m;
//	cin >> n >> m;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++) {
//			if (vis[i][j] == -1) {
//				record.clear();
//				queue<pair<int, int>>q;
//				q.emplace(i, j);
//				vis[i][j] = 1;
//				int cnt = 1;
//				while (!q.empty()) {
//					pair<int, int>cur = q.front();
//					record.push_back(cur);
//					q.pop();
//					for (int u = 0; u < 4; u++)
//					{
//						int x = cur.first + dir[u][0];
//						int y = cur.second + dir[u][1];
//						if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == 1) continue;
//						if (v[cur.first][cur.second] == v[x][y])continue;
//						vis[x][y] = 1;
//						q.emplace(x, y);
//						cnt++;
//					}
//				}
//				for (int u = 0; u < record.size(); u++)
//				{
//					dp[record[u].first][record[u].second] = cnt;
//				}
//			}
//		}
//	}
//	int askx, asky;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> askx >> asky;
//		printf("%d\n", dp[askx - 1][asky - 1]);
//	}
//	return 0;
//}