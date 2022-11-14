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
////
////int main() {
////	double h, s1, v, l, k;
////	int n;
////	cin >> h >> s1 >> v >> l >> k >> n;
////	vector<bool>flag(n, false);
////	double shortDisTime = l / v;
////	//¶¥²¿ÊÇ·ñ½Ó´¥
////	bool topHasTouch = false;
////	for (int i = 0; i < n; i++)
////	{
////		double arriveTime = (s1 - i) / v;
////		double leaveTime = (s1 + l - i) / v;
////		double carArriveDropDis = (h - 5 * arriveTime * arriveTime);
////		double carLeaveDropDis = (h - 5 * leaveTime * leaveTime);
////		if (carArriveDropDis <= k + 0.0001 && carArriveDropDis >= 0 ||
////			carLeaveDropDis <= k + 0.0001 && carLeaveDropDis >= 0) {
////			flag[i] = true;
////			topHasTouch = true;
////		}
////		else {
////			if (topHasTouch) {
////				break;
////			}
////		}
////	}
////	int cnt = 0;
////	for (int i = 0; i < flag.size(); i++)
////	{
////		if (flag[i])cnt++;
////	}
////	cout << cnt << endl;
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
//
//int main() {
//	double h, s1, v, l, k;
//	int n;
//	cin >> h >> s1 >> v >> l >> k >> n;
//	double tmax = sqrt(h / 5);
//	double tmin = sqrt((h - k) / 5);
//	int firstBall = int(s1 - v * tmin + l);
//	int lastBall = int(s1 - v * tmax);
//	firstBall = min(firstBall, n);
//	lastBall = max(0, lastBall);
//	cout << firstBall - lastBall << endl;
//	return 0;
//}