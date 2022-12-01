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
//int a, b, minn = INT_MAX;
//int k[505][505];
//int discount[505];
//void dfs(int idx, int num, int cost, vector<int>vis) {
//	if (cost > minn)return;
//	if (num == b) {
//		minn = min(minn, cost);
//		return;
//	}
//	int match = 0;
//	for (int i = 0; i < b; i++)
//	{
//		if (vis[i] || idx == i) continue;
//		if (k[idx][i] != 0 && k[idx][i] < a) {
//			vis[i] = 1;
//			match += 1;
//			cost += k[idx][i];
//			dfs(i, num + match, cost, vis);
//		}
//		else {
//			if (discount[i] != 0)continue;
//			vis[i] = 1;
//			match += 1;
//			cost += a;
//			dfs(i, num + match, cost, vis);
//		}
//	}
//}
//int main() {
//	cin >> a >> b;
//	for (int i = 0; i < b; i++)
//	{
//
//		for (int j = 0; j < b; j++) {
//			scanf_s("%d", &k[i][j]);
//			if (k[i][j] != 0) {
//				discount[i] = min(discount[i], k[i][j]);
//			}
//		}
//	}
//	vector<int>vis(b + 1);
//	for (int i = 0; i < b; i++)
//	{
//		vis[i] = 1;
//		dfs(i, 1, a, vis);
//		vis[i] = 0;
//	}
//	printf("%d", minn);
//	return 0;
//}