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
//#include<cstring>
//#include<limits.h>
//using namespace std;
//vector<pair<int, int>>dir = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1} };
//vector<pair<int, int>>loc;
//string word[105];
//bool flag[105][105];
//int n;
//bool matchCondition(int x, int y, int dirction) {
//	string s = "yizhong";
//	int boundx = x + dir[dirction].first * 6;
//	int boundy = y + dir[dirction].second * 6;
//	if (boundx < 0 || boundy < 0 || boundx >= n || boundy >= n)return false;
//	for (int i = 1; i < 7; i++)
//	{
//		int newx = x + dir[dirction].first * i;
//		int newy = y + dir[dirction].second * i;
//		if (word[newx][newy] != s[i]) {
//			return false;
//		}
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		int newx = x + dir[dirction].first * i;
//		int newy = y + dir[dirction].second * i;
//		flag[newx][newy] = true;
//	}
//	return true;
//}
//int main() {
//	memset(flag, false, sizeof(flag));
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> word[i];
//		for (size_t j = 0; j < word[i].size(); j++)
//		{
//			if (word[i][j] == 'y') {
//				loc.emplace_back(i, j);
//			}
//		}
//	}
//	for (size_t i = 0; i < loc.size(); i++)
//	{
//		for (size_t j = 0; j < 8; j++)
//		{
//			matchCondition(loc[i].first, loc[i].second, j);
//		}
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		for (size_t j = 0; j < word[i].size(); j++)
//		{
//			if (!flag[i][j]) {
//				word[i][j] = '*';
//			}
//		}
//		printf("%s\n", word[i].c_str());
//	}
//
//	return 0;
//}