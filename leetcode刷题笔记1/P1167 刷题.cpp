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
//vector<long>v;
//string start, endt;
//int year1, m1, d1, h1, minute1;
//int year2, m2, d2, h2, minute2;
//int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//long getMinuteOfMonth(int m1, int m2) {
//	long ans = 0;
//	for (int i = m1; i <= m2; i++)
//	{
//		if (i == 2 && (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)) {
//			ans += 29 * 24 * 60;
//		}
//		else {
//			ans += (long)month[i - 1] * 24 * 60;
//		}
//	}
//	return ans;
//}
//long getMinute() {
//	long  totalMinute = 0;
//	//不同年份的
//	if (year1 != year2) {
//		for (int i = year1; i < year2; i++)
//		{
//			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
//				totalMinute += 366 * 24 * 60;
//			}
//			else {
//				totalMinute += 365 * 24 * 60;
//			}
//		}
//		//计算月至年末
//		totalMinute = totalMinute - getMinuteOfMonth(1, m1 - 1);
//		totalMinute = totalMinute - (d1 - 1) * 24 * 60 - h1 * 60 - minute1;
//		totalMinute = totalMinute + getMinuteOfMonth(1, m2 - 1);
//		totalMinute = totalMinute + (d2 - 1) * 24 * 60 + h2 * 60 + minute2;
//
//	}
//	else {
//		totalMinute = getMinuteOfMonth(m1, m2 - 1);
//		//计算日
//		if (m1 == m2) {
//			totalMinute = d2 * 24 * 60 - d1 * 24 * 60 + h2 * 60 + minute2 - h1 * 60 - minute1;
//		}
//		else {
//			totalMinute = totalMinute - (d1 - 1) * 24 * 60 - h1 * 60 - minute1;
//			totalMinute = totalMinute + (d2 - 1) * 24 * 60 + h2 * 60 + minute2;
//		}
//
//	}
//	return totalMinute;
//}
//int main() {
//	int n;
//	cin >> n;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &v[i]);
//	}
//	sort(v.begin(), v.end());
//	cin >> start >> endt;
//	year1 = stoi(start.substr(0, 4));
//	m1 = stoi(start.substr(5, 2));
//	d1 = stoi(start.substr(8, 2));
//	h1 = stoi(start.substr(11, 2));
//	minute1 = stoi(start.substr(14, 2));
//	year2 = stoi(endt.substr(0, 4));
//	m2 = stoi(endt.substr(5, 2));
//	d2 = stoi(endt.substr(8, 2));
//	h2 = stoi(endt.substr(11, 2));
//	minute2 = stoi(endt.substr(14, 2));
//	long total = getMinute();
//	for (int i = 1; i < n; i++)
//	{
//		v[i] = v[i - 1] + v[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (total >= v[i])continue;
//		cout << i << endl;
//		return 0;
//	}
//	cout << n << endl;
//	return 0;
//}