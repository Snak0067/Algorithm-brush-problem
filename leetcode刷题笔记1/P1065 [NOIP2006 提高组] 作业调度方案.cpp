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
//int order[450];
//vector<vector<int>>process, processTime;
//vector<vector<pair<int, int>>>schedule;
//vector<int>plan;
//vector<int>work;
//bool cmp(pair<int, int>a, pair<int, int>b) {
//	return a.first < b.first;
//}
//int main() {
//	int m, n;
//	cin >> m >> n;
//	plan.resize(n + 1, 1);
//	work.resize(n + 1);
//	schedule.resize(m + 1);
//	process.assign(n + 1, vector<int>(m + 1));
//	processTime.assign(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= m; i++)
//	{
//		schedule[i].emplace_back(0, INT_MAX);
//	}
//
//	for (int i = 0; i < m * n; i++)
//	{
//		cin >> order[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			cin >> process[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			cin >> processTime[i][j];
//		}
//	}
//	for (int i = 0; i < m * n; i++)
//	{
//		int id = order[i];
//		int machineId = process[id][plan[id]];
//		int workTime = processTime[id][plan[id]];
//		vector<pair<int, int>>v = schedule[machineId];
//		for (int j = 0; j < v.size(); j++)
//		{
//			int lastTime = work[id];
//			int begin = v[j].first, end = v[j].second;
//			if (end - max(lastTime, begin) >= workTime) {
//				if (begin < lastTime) {
//					schedule[machineId][j].second = lastTime;
//					schedule[machineId].emplace_back(lastTime + workTime, end);
//					sort(schedule[machineId].begin(), schedule[machineId].end(), cmp);
//				}
//				else {
//					schedule[machineId][j].first = begin + workTime;
//				}
//				work[id] = max(lastTime, begin) + workTime;
//				break;
//			}
//		}
//		plan[id]++;
//	}
//	int maxn = INT_MIN;
//	for (int i = 1; i < schedule.size(); i++)
//	{
//		maxn = max(schedule[i].back().first, maxn);
//	}
//	cout << maxn << endl;
//	return 0;
//}