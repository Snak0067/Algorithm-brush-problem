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
//
//int main() {
//	int n, m;
//	cin >> n;
//	string need;
//	cin >> need >> m;
//	int cnt = 0;
//	for (char c : need) {
//		cnt *= n;
//		if (isdigit(c)) {
//			cnt += (c - '0');
//		}
//		else {
//			cnt += (c - 'A' + 10);
//		}
//	}
//	vector<int>v;
//	while (cnt != 0) {
//		v.push_back(cnt % m);
//		cnt /= m;
//	}
//	vector<char>ans;
//	for (int x : v) {
//		char temp;
//		if (x >= 10) {
//			temp = 'A' + x - 10;
//		}
//		else {
//			temp = x + '0';
//		}
//		ans.push_back(temp);
//	}
//	reverse(ans.begin(), ans.end());
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i];
//	}
//	return 0;
//}