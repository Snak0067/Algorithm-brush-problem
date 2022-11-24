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
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int v[35][35];
//int vis[35][35];
//struct p
//{
//	int x, y;
//};
//vector<p>ps;
//int n;
//
//bool dfs(int x, int y) {
//	vis[x][y] = 1;
//	ps.push_back({ x, y });
//	for (int i = 0; i < 4; i++)
//	{
//		int newx = x + dir[i][0];
//		int newy = y + dir[i][1];
//		if (newx < 0 || newx >= n || newy < 0 || newy >= n) return false;
//		if (v[newx][newy] == 1)continue;
//		if (vis[newx][newy] == 0 && !dfs(newx, newy)) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//
//	cin >> n;
//	for (int i = 0; i < n * n; i++)
//	{
//		cin >> v[i / n][i % n];
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (v[i][j])continue;
//			if (vis[i][j])continue;
//			ps.clear();
//			if (dfs(i, j)) {
//				for (int u = 0; u < ps.size(); u++)
//				{
//					v[ps[u].x][ps[u].y] = 2;
//				}
//				for (int u = 0; u < n; u++)
//				{
//					for (int k = 0; k < n; k++)
//					{
//						if (k != 0)printf(" ");
//						printf("%d", v[u][k]);
//					}
//					printf("\n");
//				}
//				return 0;
//			}
//		}
//	}
//
//	return 0;
//}