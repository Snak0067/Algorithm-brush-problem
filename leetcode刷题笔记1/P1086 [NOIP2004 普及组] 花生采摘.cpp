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
//struct pea
//{
//	int x, y, v;
//	pea() {}
//	pea(int i, int j, int k) {
//		x = i;
//		y = j;
//		v = k;
//	}
//};
//vector<vector<int>>v;
//vector<pea>peanut;
//bool cmp(pea p1, pea p2) {
//	return p1.v > p2.v;
//}
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	v.assign(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			cin >> v[i][j];
//			if (v[i][j] != 0) {
//				peanut.emplace_back(i, j, v[i][j]);
//			}
//		}
//	}
//	sort(peanut.begin(), peanut.end(), cmp);
//	int cnt = 0, x = 0, y = peanut[0].y;
//	for (int i = 0; i < peanut.size(); i++)
//	{
//		int dis = abs(peanut[i].x - x) + abs(peanut[i].y - y);
//		if (k >= (dis + 1 + peanut[i].x)) {
//			cnt += peanut[i].v;
//			x = peanut[i].x;
//			y = peanut[i].y;
//			k -= dis + 1;
//		}
//		else {
//			break;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}