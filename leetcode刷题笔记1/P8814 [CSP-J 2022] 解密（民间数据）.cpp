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
//using namespace std;
//
//int main() {
//	int k;
//	long long n, e, d;
//	cin >> k;
//	for (int i = 0; i < k; i++) {
//		cin >> n >> e >> d;
//		long long m = n - e * d + 2;
//		double p = (m - sqrt(m * m - 4 * n)) / 2.0;
//		long long p1 = p;
//		long long q = m - p;
//		if (m * m - n * 4 < 0 || p1 != p || p * q != n) {
//			cout << "NO" << endl;
//		}
//		else {
//			printf("%lld %lld\n", p1, q);
//		}
//	}
//	return 0;
//}