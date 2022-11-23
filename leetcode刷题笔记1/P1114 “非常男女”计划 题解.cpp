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
//int l[200010], r[200010];
//int main() {
//	int sum0 = 0, sum1 = 0;
//	int ans, n, x;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		if (x == 1) {
//			sum1++;
//		}
//		else {
//			sum0++;
//		}
//		int differ = sum0 - sum1 + n;
//		if (!l[differ] && differ != n) {
//			l[differ] = i;
//		}
//		else {
//			r[differ] = i;
//		}
//	}
//	int maxn = 0;
//	for (int i = 0; i <= 2 * n; i++)
//	{
//		maxn = max(maxn, r[i] - l[i]);
//	}
//	cout << maxn << endl;
//	return 0;
//}