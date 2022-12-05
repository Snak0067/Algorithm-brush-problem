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
////unordered_set<string>mmap;
////vector<pair<int, int>>v;
////vector<pair<double, double>>t;
////int main() {
////	int n;
////	cin >> n;
////	for (int i = 0; i < n; i++)
////	{
////		int x, y;
////		scanf_s("%d%d", &x, &y);
////		v.emplace_back(x, y);
////		mmap.insert(to_string(x) + "_" + to_string(y));
////	}
////	for (int i = 1; i < n; i++)
////	{
////		double x = (v[0].first * 1.0 + v[i].first) / 2;
////		double y = (v[0].second * 1.0 + v[i].second) / 2;
////		t.emplace_back(x, y);
////	}
////	for (int i = 0; i < t.size(); i++)
////	{
////		double x = t[i].first, y = t[i].second;
////		bool find = true;
////		for (int j = 0; j < n; j++)
////		{
////			int newx = int(x * 2 - v[j].first);
////			int newy = int(y * 2 - v[j].second);
////			if (mmap.count(to_string(newx) + "_" + to_string(newy)) == false) {
////				find = false;
////				break;
////			}
////		}
////		if (find) {
////			printf("V.I.P. should stay at (%.1f,%.1f).", x, y);
////			return 0;
////		}
////	}
////	printf("This is a dangerous situation!");
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
//struct point {
//	int x, y;
//};
//vector<point>v(20000);
//int n;
//bool cmp(point p1, point p2) {
//	if (p1.y != p2.y)return p1.y < p2.y;
//	return p1.x < p2.x;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d%d", &v[i].x, &v[i].y);
//	}
//	sort(v.begin(), v.begin() + n, cmp);
//	double x = (v[0].x * 1.0 + v[n - 1].x) / 2;
//	double y = (v[0].y * 1.0 + v[n - 1].y) / 2;
//	if (n % 2 == 1) {
//		if (x - v[n / 2].x > 1e-6 || y - v[n / 2].y > 1e-6) {
//			printf("This is a dangerous situation!");
//			return 0;
//		}
//	}
//	for (int i = 1; i < n / 2; i++)
//	{
//		double tempx = (v[i].x * 1.0 + v[n - i - 1].x) / 2;
//		double tempy = (v[i].y * 1.0 + v[n - i - 1].y) / 2;
//		if (tempx != x || tempy != y) {
//			printf("This is a dangerous situation!");
//			return 0;
//		}
//	}
//	printf("V.I.P. should stay at (%.1f,%.1f).", x, y);
//	return 0;
//}