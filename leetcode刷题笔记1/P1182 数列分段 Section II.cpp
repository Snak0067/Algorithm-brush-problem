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
//int n, m, l;
//long long r;
//int v[100010];
//bool check(int x) {
//	int tmp = 0, num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (tmp + v[i] <= x) {
//			tmp += v[i];
//		}
//		else {
//			tmp = v[i];
//			num++;
//		}
//	}
//	return num >= m;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &v[i]);
//		l = max(l, v[i]);
//		r += v[i];
//	}
//	while (l < r) {
//		int mid = (l + r) >> 1;
//		if (check(mid)) {
//			l = mid + 1;
//		}
//		else {
//			r = mid;
//		}
//	}
//	cout << l << endl;
//	return 0;
//}