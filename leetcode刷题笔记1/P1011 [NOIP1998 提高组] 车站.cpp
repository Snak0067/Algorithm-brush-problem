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
//int a, n, m, x;
//int main() {
//	cin >> a >> n >> m >> x;
//	vector<pair<int, int>>aboard(n);
//	vector<pair<int, int>>debarkation(n);
//	vector<pair<int, int>>car(n);
//	aboard[0].first = car[0].first = 1;
//	aboard[1].second = debarkation[1].second = car[1].first = 1;
//	for (int i = 2; i < n - 1; i++) {
//		aboard[i].first = aboard[i - 1].first + aboard[i - 2].first;
//		aboard[i].second = aboard[i - 1].second + aboard[i - 2].second;
//		debarkation[i] = aboard[i - 1];
//		car[i].first = car[i - 1].first + aboard[i - 2].first;
//		car[i].second = car[i - 1].second + aboard[i - 2].second;
//	}
//	int b = (m - car[n - 2].first * a) / car[n - 2].second;
//	cout << car[x - 1].first * a + car[x - 1].second * b << endl;
//	return 0;
//}