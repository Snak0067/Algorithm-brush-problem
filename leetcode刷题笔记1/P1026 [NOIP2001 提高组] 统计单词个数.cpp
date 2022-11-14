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
//unordered_map<char, vector<string>>mmap;
//int main() {
//	int p, k, h;
//	cin >> p >> k;
//	string s, temp;
//	for (int i = 0; i < p; i++)
//	{
//		cin >> temp;
//		s += temp;
//	}
//	cin >> h;
//	for (int i = 0; i < h; i++)
//	{
//		cin >> temp;
//		mmap[temp[0]].push_back(temp);
//	}
//	int cnt = 0;
//	vector<int>status(s.length(), 0);
//	for (int i = 0; i < s.length(); i++)
//	{
//		vector<string>v = mmap[s[i]];
//		for (int j = 0; j < v.size(); j++)
//		{
//			if (s.substr(i, v[j].length()) == v[j]) {
//				cnt++;
//				break;
//			}
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}