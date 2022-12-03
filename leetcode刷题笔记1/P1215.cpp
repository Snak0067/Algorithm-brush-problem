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
//int vis[25][25][25];
//int a, b, c;
//void dfs(int i, int j, int k) {
//	vis[i][j][k] = 1;
//	if (i == 0) {
//		v.push_back(k);
//	}
//	int xa, xb, xc;
//	if (i != 0) {
//		xb = min(b, i + j);
//		xa = i - (xb - j);
//		if (vis[xa][xb][k] == 0) {
//			dfs(xa, xb, k);
//		}
//		xc = min(c, i + k);
//		xa = i - (xc - k);
//		if (vis[xa][j][xc] == 0) {
//			dfs(xa, j, xc);
//		}
//	}
//	if (j != 0) {
//		xa = min(a, i + j);
//		xb = j - (xa - i);
//		if (vis[xa][xb][k] == 0) {
//			dfs(xa, xb, k);
//		}
//		xc = min(c, j + k);
//		xb = j - (xc - k);
//		if (vis[i][xb][xc] == 0) {
//			dfs(i, xb, xc);
//		}
//	}
//	if (k != 0) {
//		xa = min(a, i + k);
//		xc = k - (xa - i);
//		if (vis[xa][j][xc] == 0) {
//			dfs(xa, j, xc);
//		}
//		xb = min(b, j + k);
//		xc = k - (xb - j);
//		if (vis[i][xb][xc] == 0) {
//			dfs(i, xb, xc);
//		}
//	}
//}
//int main() {
//	cin >> a >> b >> c;
//	dfs(0, 0, c);
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (i != 0)printf(" ");
//		printf("%d", v[i]);
//	}
//	return 0;
//}