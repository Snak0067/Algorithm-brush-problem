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
int depth[100005];
int way[100005];
int vis[100005];
vector<int>v[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf_s("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int>q;
	q.push(1);
	way[1] = 1;
	vis[1] = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < v[top].size(); i++)
		{
			int nxt = v[top][i];
			if (vis[nxt] == 0) {
				vis[nxt] = 1;
				q.push(nxt);
				depth[nxt] = depth[top] + 1;
			}
			if (depth[nxt] == depth[top] + 1) {
				way[nxt] = (way[nxt] + way[top]) % 100003;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", way[i]);
	}
	return 0;
}