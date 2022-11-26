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
//double getTotal(int monthlyPayment, int m, double rate) {
//	double total = 0;
//	for (int i = 1; i <= m; i++)
//	{
//		total += monthlyPayment / pow(1 + rate, i);
//	}
//	return total;
//}
//void print(double k) {
//	printf("%.1f", k * 100);
//}
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	double left = 0.01, right = 0.01;
//	while (getTotal(m, k, right) > n) {
//		left = right;
//		right *= 2;
//	}
//	while (right - left > 0.0001) {
//		double mid = (left + right) / 2;
//		double midTotal = getTotal(m, k, mid);
//		if (midTotal > n) {
//			left = mid;
//		}
//		else if (midTotal < n) {
//			right = mid;
//		}
//	}
//	print((right + left) / 2);
//	return 0;
//}