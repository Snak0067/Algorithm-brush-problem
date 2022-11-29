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
//int r, c, n;
//vector<int>rv[65];//ÐÐ
//vector<int>cv[65];//ÁÐ
//vector<pair<int, int>>v;
//vector<pair<int, int>>problem;
//bool solve(int idx) {
//	pair<int, int>p = v[idx];
//	int x = p.first, y = p.second, xid = 0, yid = 0;
//	for (int i = 0; i < rv[x].size(); i++)
//	{
//		if (rv[x][i] == y) {
//			rv[x][i] = 0;
//			xid = i;
//			break;
//		}
//	}
//	for (int i = 0; i < cv[y].size(); i++)
//	{
//		if (cv[y][i] == x) {
//			cv[y][i] = INT_MAX;
//			yid = i;
//			break;
//		}
//	}
//	for (pair<int, int>it : problem)
//	{
//		int resistx = 0, resisty = 0, newx = it.first, newy = it.second;
//		for (int j = 0; j < rv[newx].size(); j++)
//		{
//			if (rv[newx][j] > y)resistx++;
//		}
//		for (int j = 0; j < cv[newy].size(); j++)
//		{
//			if (cv[newy][j] < x)resisty++;
//		}
//		if (resistx >= 1 && resisty >= 1) {
//			return false;
//		}
//	}
//	rv[x][xid] = y;
//	cv[y][yid] = x;
//	return true;
//}
//int main() {
//	cin >> r >> c >> n;
//	bool safe = true;
//	for (int i = 0; i < n; i++)
//	{
//		int x, y;
//		scanf_s("%d%d", &x, &y);
//		v.emplace_back(x, y);
//		rv[x].push_back(y);
//		cv[y].push_back(x);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int x = v[i].first, y = v[i].second;
//		if (rv[x].size() >= 2 && cv[y].size() >= 2) {
//			int resistx = 0, resisty = 0;
//			for (int j = 0; j < rv[x].size(); j++)
//			{
//				if (rv[x][j] > y)resistx++;
//			}
//			for (int j = 0; j < cv[y].size(); j++)
//			{
//				if (cv[y][j] < x)resisty++;
//			}
//			if (resistx >= 1 && resisty >= 1) {
//				problem.emplace_back(x, y);
//				safe = false;
//			}
//		}
//	}
//	if (safe) {
//		cout << 0 << endl;
//		return 0;
//	}
//	else {
//		for (int i = 0; i < n; i++)
//		{
//			if (solve(i)) {
//				printf("%d\n%d", 1, i + 1);
//				return 0;
//			}
//		}
//	}
//	printf("-1\n");
//	return 0;
//}