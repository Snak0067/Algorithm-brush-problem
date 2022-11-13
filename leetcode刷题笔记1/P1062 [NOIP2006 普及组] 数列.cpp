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
//	int k, n, i = 1;
//	long long ans = 0;
//	cin >> k >> n;
//	while (true) {
//		while (pow(2, i) - 1 < n) {
//			i++;
//		}
//		ans += pow(k, i - 1);
//		n = n - pow(2, i - 1);
//		i = 1;
//		if (n == 0) {
//			cout << ans << endl;
//			return 0;
//		}
//	}
//
//	return 0;
//}