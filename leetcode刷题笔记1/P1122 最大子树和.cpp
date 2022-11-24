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
//int beauty[16500];
//vector<int>vis;
//vector<int>branch[16500];
//int dfs(int x) {
//	int sum = beauty[x];
//	vis[x] = 1;
//	for (int i = 0; i < branch[x].size(); i++)
//	{
//		if (vis[branch[x][i]])continue;
//		int childBeauty = dfs(branch[x][i]);
//		if (childBeauty > 0) {
//			sum += childBeauty;
//		}
//	}
//	return sum;
//}
//int main() {
//	int n;
//	cin >> n;
//	vis.resize(n+1);
//	int start = 1, maxn = INT_MIN;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> beauty[i];
//		if (beauty[i] > maxn) {
//			maxn = beauty[i];
//			start = i;
//		}
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		branch[a].push_back(b);
//		branch[b].push_back(a);
//	}
//	cout << dfs(start) << endl;
//	return 0;
//}