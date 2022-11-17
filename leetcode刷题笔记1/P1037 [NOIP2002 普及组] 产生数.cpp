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
//#include<cstring>
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
//int s[33], num[33], suffix[33][16], vis[10];
//int cnt = 1;
//vector<int> mul(vector<int>v, int x) {
//	vector<int>xv;
//	while (x != 0) {
//		xv.push_back(x % 10);
//		x /= 10;
//	}
//	vector<int>ans(v.size() + xv.size(), 0);
//	for (size_t i = 0; i < xv.size(); i++)
//	{
//		int flag = 0;
//		for (size_t j = 0; j < v.size(); j++)
//		{
//			int temp = v[j] * xv[i] + flag + ans[i + j];
//			ans[i + j] = temp % 10;
//			flag = temp / 10;
//		}
//		if (flag != 0) {
//			ans[i + v.size()] = flag;
//		}
//	}
//	if (ans.back() == 0) {
//		ans.pop_back();
//	}
//	return ans;
//}
//void dfs(int x, int y) {
//	if (vis[y])return;
//	vis[x] = 1;
//	cnt++;
//	for (int i = 0; i < num[y]; i++)
//	{
//		dfs(y, suffix[y][i]);
//	}
//}
//int main() {
//	int n, k;
//	string str;
//	cin >> str >> k;
//	n = str.length();
//	vector<int>res(1, 1);
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
//	for (int i = 0; i < n; i++)
//	{
//		cnt = 1;
//		for (int j = 0; j < num[s[i]]; j++)
//		{
//			dfs(s[i], suffix[s[i]][j]);
//		}
//		memset(vis, 0, sizeof(vis));
//		if (cnt != 1)res = mul(res, cnt);
//	}
//	while (res.back() == 0)res.pop_back();
//	for (int i = res.size() - 1; i >= 0; i--)
//	{
//		cout << res[i];
//	}
//	return 0;
//}