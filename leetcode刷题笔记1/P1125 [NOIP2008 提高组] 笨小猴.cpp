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
//bool prime(int x) {
//	if (x <= 1)return false;
//	for (int i = 2; i * i <= x; i++)
//	{
//		if (x % i == 0)return false;
//	}
//	return true;
//}
//int main() {
//	vector<int>cnt(26, 0);
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.length(); i++)
//	{
//		cnt[s[i] - 'a']++;
//	}
//	int maxn = 0, minn = INT_MAX;
//	for (int i = 0; i < 26; i++)
//	{
//		maxn = max(maxn, cnt[i]);
//		if (cnt[i] != 0)minn = min(cnt[i], minn);
//	}
//	if (prime(maxn - minn)) {
//		printf("Lucky Word\n%d", maxn - minn);
//	}
//	else {
//		printf("No Answer\n0");
//	}
//	return 0;
//}