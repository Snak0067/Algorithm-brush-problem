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
//struct p {
//	int x, y;
//};
//vector<p>v;
//int main() {
//	int x1, x2, y1, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	double mid = ((double)x1 + x2) / 2;
//	int n, x, y;
//	cin >> n;
//	long long max1 = LLONG_MIN, max2 = LLONG_MIN, id1 = 0, id2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d%d", &x, &y);
//		v.push_back({ x,y });
//		long long dis;
//		if (x < mid) {
//			dis = pow(abs(x - x1), 2) + pow(abs(y - y1), 2);
//			if (dis > max1) {
//				max1 = dis;
//				id1 = i;
//			}
//		}
//		else {
//			dis = pow(abs(x - x2), 2) + pow(abs(y - y2), 2);
//			if (dis > max2) {
//				max2 = dis;
//				id2 = i;
//			}
//		}
//	}
//	long long ans = LLONG_MAX;
//	long long disToRight = pow(abs(x1 - v[id2].x), 2) + pow(abs(y1 - v[id2].y), 2);
//	long long disToLeft = pow(abs(x2 - v[id1].x), 2) + pow(abs(y2 - v[id1].y), 2);
//	max1 = max1 == LLONG_MIN ? 0 : max1;
//	max2 = max2 == LLONG_MIN ? 0 : max2;
//	//1¡¢ÅÐ¶Ï×ó²àÄÜ·ñÀ¹½Ø×îÓÒ²àµ¼µ¯
//	if (max1 >= disToRight) {
//		ans = min(ans, disToRight);
//	}
//	//2¡¢ÅÐ¶ÏÓÒ²àÄÜ·ñÀ¹½Ø×î×ó²àµ¼µ¯
//	if (max2 >= disToLeft) {
//		ans = min(ans, disToLeft);
//	}
//	//3¡¢ÅÐ¶Ï×óÓÒ²à×îÔ¶
//	ans = min(ans, max1 + max2);
//	cout << ans << endl;
//	return 0;
//}