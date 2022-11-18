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
//struct road {
//	int x, y, cost;
//};
//int n, m;
//vector<vector<int>>vis;
//vector<vector<int>>nxt;
//vector<road>v;
//bool cmp(road r1, road r2) {
//	return r1.cost < r2.cost;
//}
//void dfs(int cur, vector<int>visit, int& visitNum) {
//	visit[cur] = 1;
//	visitNum += 1;
//	if (visitNum == n) {
//		return;
//	}
//	for (int i = 0; i < nxt[cur].size(); i++)
//	{
//		int next = nxt[cur][i];
//		if (visit[next] == -1 && vis[cur][next] == 1) {
//			dfs(nxt[cur][i], visit, visitNum);
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	vis.assign(n + 1, vector<int>(n + 1, -1));
//	nxt.resize(n + 1);
//	v.resize(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> v[i].x >> v[i].y >> v[i].cost;
//		nxt[v[i].x].push_back(v[i].y);
//		nxt[v[i].y].push_back(v[i].x);
//	}
//	sort(v.begin(), v.end(), cmp);
//	int ans = 0;
//	unordered_set<int>cnt;
//	vector<int>visit(n + 1, -1);
//	for (size_t i = 0; i < m; i++)
//	{
//		vis[v[i].x][v[i].y] = 1;
//		vis[v[i].y][v[i].x] = 1;
//		cnt.insert(v[i].x);
//		cnt.insert(v[i].y);
//		ans = max(ans, v[i].cost);
//		if (cnt.size() >= n) {
//			int visitNum = 0;
//			dfs(v[i].x, visit, visitNum);
//			if (visitNum == n) {
//				break;
//			}
//		}
//
//	}
//	cout << ans << endl;
//	return 0;
//}
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
struct road {
	int x, y, cost;
};
bool cmp(road r1, road r2) {
	return r1.cost < r2.cost;
}
vector<road>v;
int f[10005];
int n, m;
int find(int x) {
	if (f[x] == x) {
		return x;
	}
	return find(f[x]);
}
int main() {
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i].x >> v[i].y >> v[i].cost;
	}
	for (int i = 0; i < n; i++)
	{
		f[i] = i;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		int fx = find(v[i].x);
		int fy = find(v[i].y);
		if (fx != fy) {
			f[fx] = fy;
			n--;
		}
		if (n == 1) {
			cout << v[i].cost << endl;
			return 0;
		}
	}
	return 0;
}