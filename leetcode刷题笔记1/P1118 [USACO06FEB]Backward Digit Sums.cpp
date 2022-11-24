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
//vector<int>v;
//vector<int>ans;
//vector<int>triangle;
//vector<int>vis;
//int n, target;
//bool dfs(int x, int sum) {
//	if (sum > target)return false;
//	if (x == n) {
//		if (sum == target) {
//			ans = v;
//			return true;
//		}
//		return false;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (vis[i])continue;
//		v.push_back(i);
//		vis[i] = 1;
//		if (dfs(x + 1, sum + triangle[x] * i)) {
//			return true;
//		}
//		v.pop_back();
//		vis[i] = 0;
//	}
//	return false;
//}
//int main() {
//	cin >> n >> target;
//	vis.resize(n + 1);
//	triangle.resize(n);
//	triangle[0] = triangle[n - 1] = 1;
//	if (n > 1) {
//		for (int i = 1; i * 2 < n; i++)
//		{
//			triangle[i] = triangle[n - i - 1] = triangle[i - 1] * (n - i) / i;
//		}
//	}
//	dfs(0, 0);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		if (i != 0)printf(" ");
//		printf("%d", ans[i]);
//	}
//	return 0;
//}