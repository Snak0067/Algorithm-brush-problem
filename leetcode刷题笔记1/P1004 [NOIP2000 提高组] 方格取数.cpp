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
//const int int_min = -2147483647 - 1;
//const int int_max = 2147483647;
//
//struct nod {
//	int x, y, v;
//	bool used = false;
//	nod(int a, int b, int c) {
//		x = a; y = b; v = c;
//	}
//	vector<int>post;
//};
//vector<nod>nods;
//int maxn = int_min;
//vector<int>ans;
//vector<int>visit;
//void dfs(int i, int cur, vector<int>path, vector<int>vis) {
//	cur += nods[i].v;
//	path.push_back(i);
//	vis[i] = true;
//	visit[i] = true;
//	if (cur > maxn) {
//		maxn = cur;
//		ans = path;
//	}
//	vector<int>post = nods[i].post;
//	for (int i = 0; i < post.size(); i++) {
//		if (vis[post[i]])continue;
//		dfs(post[i], cur, path, vis);
//		break;
//	}
//}
//bool cmp(int x, int y) {
//	return nods[x].v > nods[y].v;
//}
//int main() {
//	int n, x = -1, y = -1, value = -1;
//	cin >> n;
//	while (x != 0 || y != 0 || value != 0) {
//		scanf_s("%d%d%d", &x, &y, &value);
//		nods.emplace_back(x, y, value);
//	}
//	nods.pop_back();
//	int k = nods.size();
//	for (int i = 0; i < k - 1; i++) {
//		for (int j = i + 1; j < k; j++) {
//			if (nods[i].x <= nods[j].x && nods[i].y <= nods[j].y) {
//				nods[i].post.push_back(j);
//			}
//			else if (nods[i].x >= nods[j].x && nods[i].y >= nods[j].y) {
//				nods[j].post.push_back(i);
//			}
//		}
//	}
//	for (int i = 0; i < nods.size(); i++) {
//		sort(nods[i].post.begin(), nods[i].post.end(), cmp);
//	}
//	visit.resize(nods.size());
//	vector<int>vis(nods.size());
//	for (int i = 0; i < nods.size(); i++) {
//		if (visit[i])continue;
//		dfs(i, 0, {}, vis);
//	}
//	int result = maxn;
//	maxn = int_min;
//	fill(visit.begin(), visit.end(), 0);
//	for (int index : ans) {
//		visit[index] = 1;
//		vis[index] = 1;
//	}
//	ans.clear();
//	for (int i = 0; i < nods.size(); i++) {
//		if (visit[i])continue;
//		dfs(i, 0, {}, vis);
//	}
//	cout << result + maxn << endl;
//	return 0;
//}