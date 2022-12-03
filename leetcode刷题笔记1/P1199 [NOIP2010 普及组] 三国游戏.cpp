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
//int n, num, ans = 0, rest;
//int v[505][505], vis[505];
//vector<int>han, com;
//int findp() {
//	int maxn = 0, idx = 0;
//	for (int i = 0; i < han.size(); i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (vis[j] || han[i] == j)continue;
//			if (v[han[i]][j] > maxn) {
//				idx = j;
//				maxn = v[han[i]][j];
//			}
//		}
//	}
//	return idx;
//}
//int hanpk() {
//	int x, y, maxn = 0;
//	for (int i = 0; i < han.size() - 1; i++)
//	{
//		for (int j = i + 1; j < han.size(); j++)
//		{
//			if (v[han[i]][han[j]] > maxn) {
//				x = han[i];
//				y = han[j];
//				maxn = v[han[i]][han[j]];
//			}
//		}
//	}
//	return maxn;
//}
//int compk() {
//	int x, y, maxn = 0;
//	for (int i = 0; i < com.size() - 1; i++)
//	{
//		for (int j = i + 1; j < com.size(); j++)
//		{
//			if (v[com[i]][com[j]] > maxn) {
//				x = com[i];
//				y = com[j];
//				maxn = v[com[i]][com[j]];
//			}
//		}
//	}
//	return maxn;
//}
//void init(int i) {
//	fill(vis, vis + n, 0);
//	vis[i] = 1;
//	han.clear();
//	com.clear();
//	han.push_back(i);
//	rest = n - 1;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			scanf_s("%d", &num);
//			v[i][j] = v[j][i] = num;
//		}
//	}
//	bool res = false;
//	int maxn = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int max1 = 0, max2 = 0;
//		for (int j = 0; j < n; j++) {
//			if (i == j)continue;
//			if (v[i][j] > max2) {
//				max1 = max2;
//				max2 = v[i][j];
//			}
//			else if (v[i][j] > max1) {
//				max1 = v[i][j];
//			}
//		}
//		maxn = max(max1, maxn);
//	}
//	printf("1\n%d", maxn);
//	return 0;
//}