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
//
//int n, a, b;
//int level[205];
//int vis[205];
//vector<int>pre[200];
//int mint = INT_MAX;
///* 深度优先搜索 */
//void dfs(int x, int cur) {
//	if (x == b) {
//		mint = min(cur, mint);
//		return;
//	}
//	if (x + level[x] <= n && vis[x + level[x]] == 0) {
//		vis[x + level[x]] ++;
//		dfs(x + level[x], cur + 1);
//		vis[x + level[x]] --;
//	}
//	if (x - level[x] >= 1 && vis[x - level[x]] == 0) {
//		vis[x - level[x]] ++;
//		dfs(x - level[x], cur + 1);
//		vis[x - level[x]] --;
//	}
//}
//
///* 深度搜索测试  60分 */
//void dfsTest() {
//	if (pre[b].size() == 0) {
//		cout << -1 << endl;
//	}
//	else {
//		vis[a]++;
//		dfs(a, 0);
//		cout << mint << endl;
//	}
//}
///* 双向广度搜索 AC 100分 */
//void bfs() {
//	queue<int>forward, backward;
//	//用来记录节点是否遍历及对应深度
//	unordered_map<int, int>left, right;
//	forward.push(a);
//	backward.push(b);
//	int deep = 0;
//	left[a] = 0;
//	right[b] = 0;
//	while (forward.size() > 0 || backward.size() > 0) {
//		deep++;
//		int forwardNum = forward.size();
//		int backNum = backward.size();
//		//正向遍历一次
//		for (int i = 0; i < forwardNum; i++)
//		{
//			int top = forward.front();
//			forward.pop();
//			//如果逆向搜索之前遇到过,说明相遇
//			if (right.count(top)) {
//				printf("%d", right[top] + left[top]);
//				return;
//			}
//			//进行拓展
//			int up = top + level[top], down = top - level[top];
//			if (up <= n && !left.count(up)) {
//				left[up] = deep;
//				forward.push(up);
//			}
//			if (down >= 1 && !left.count(down)) {
//				left[down] = deep;
//				forward.push(down);
//			}
//		}
//		//反向遍历一次
//		for (int i = 0; i < backNum; i++)
//		{
//			int top = backward.front();
//			backward.pop();
//			//如果正向搜索之前遇到过,说明相遇
//			if (left.count(top)) {
//				printf("%d", left[top] + right[top]);
//				return;
//			}
//			//进行拓展
//			for (int j = 0; j < pre[top].size(); j++)
//			{
//				if (pre[top][j] <= n && !right.count(pre[top][j])) {
//					right[pre[top][j]] = deep;
//					backward.push(pre[top][j]);
//				}
//			}
//		}
//	}
//	//双向遍历完成但没有相遇，则说明无法到达
//	printf("-1");
//	return;
//}
//
//int main() {
//	cin >> n >> a >> b;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> level[i];
//		if (i - level[i] >= 1) {
//			pre[i - level[i]].push_back(i);
//		}
//		if (i + level[i] <= n) {
//			pre[i + level[i]].push_back(i);
//		}
//	}
//	bfs();
//
//	return 0;
//}