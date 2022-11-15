////#include<iostream>
////#include<unordered_map>
////#include<set>
////#include<vector>
////#include<string>
////#include<cmath>
////#include<algorithm>
////#include<map>
////#include<stack>
////#include<unordered_set>
////#include<queue>
////#include<limits.h>
////using namespace std;
////unordered_map<int, unordered_set<int>>rule;
////int main() {
////	string s;
////	int n;
////	cin >> s >> n;
////	for (int i = 0; i < n; i++)
////	{
////		int origin, changed;
////		cin >> origin >> changed;
////		rule[origin].insert(changed);
////	}
////	bool changed = true;
////	while (changed) {
////		changed = false;
////		for (auto it = rule.begin(); it != rule.end(); it++) {
////			unordered_set<int>changeSet = it->second;
////			for (auto i = changeSet.begin(); i != changeSet.end(); i++)
////			{
////				for (auto j = rule[*i].begin(); j != rule[*i].end(); j++)
////				{
////					if (it->first == *j)continue;
////					if (!rule[it->first].count(*j)) {
////						rule[it->first].insert(*j);
////						changed = true;
////					}
////				}
////			}
////		}
////	}
////	int cnt = 1;
////	for (int i = 0; i < s.length(); i++)
////	{
////		cnt *= (1 + rule[s[i] - '0'].size());
////	}
////	cout << cnt << endl;
////	return 0;
////}
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
//int s[33], num[33], suffix[33][16];
//int vis[10];
//int cnt = 1;
//void dfs(int x, int y) {
//	if (vis[y])return;
//	vis[x] = 1;
//	cnt++;
//	for (int i = 0; i < num[y]; i++)
//	{
//		dfs(y, suffix[y][i]);
//	}
//	vis[x] = 0;
//}
//int main() {
//	int n, k;
//	string str;
//	cin >> str >> k;
//	n = str.length();
//	for (int i = 0; i < n; i++)
//	{
//		s[i] = str[i] - '0';
//	}
//	for (int i = 0; i < k; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		suffix[x][num[x]] = y;
//		num[x]++;
//	}
//	int res = 1;
//	for (int i = 0; i < n; i++)
//	{
//		cnt = 1;
//		for (int j = 0; j < num[s[i]]; j++)
//		{
//			dfs(s[i], suffix[s[i]][j]);
//		}
//		res *= cnt;
//	}
//	cout << res << endl;
//	return 0;
//}