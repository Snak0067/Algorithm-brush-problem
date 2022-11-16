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
////vector<long long>v;
////unordered_map<long long, int>cnt;
////int main() {
////	int n;
////	long long c, num, ans = 0;
////	cin >> n >> c;
////	for (size_t i = 0; i < n; i++)
////	{
////		cin >> num;
////		if (!cnt.count(num)) {
////			v.push_back(num);
////		}
////		cnt[num]++;
////	}
////	sort(v.begin(), v.end());
////	int l = 0, r = 1;
////	while (l < v.size() && r < v.size()) {
////		if (v[r] - v[l] == c) {
////			ans += cnt[v[r]] * cnt[v[l]];
////			l++;
////			r++;
////		}
////
////		else if (v[r] - v[l] > c) {
////			l++;
////		}
////		else {
////			r++;
////		}
////	}
////	cout << ans << endl;
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
//vector<long long>v;
//unordered_map<long long, long long>cnt;
//unordered_map<long long, long long>repeat;
//int main() {
//	int n;
//	long long c, num, ans = 0;
//	cin >> n >> c;
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> num;
//		cnt[num]++;
//		if (!repeat.count(num - c)) {
//			v.push_back(num - c);
//			repeat[num - c] = 1;
//		}
//	}
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (cnt.count(v[i])) {
//			ans += cnt[v[i]] * cnt[v[i] + c];
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}