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
//	int n, up, down, total = 0;
//	cin >> n;
//	vector<int>v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//		total += v[i];
//	}
//	cin >> down >> up;
//	if (total<down * n || total>up * n) {
//		cout << -1 << endl;
//		return 0;
//	}
//	int low = 0, high = 0;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (v[i] < down) {
//			low += (down - v[i]);
//		}
//		else if (v[i] > up) {
//			high += v[i] - up;
//		}
//	}
//	cout << max(low, high) << endl;
//	return 0;
//}